//
// Created by rkuang on 2020/12/27.
//

#include "PandR_GA.h"
#include "ChessBoard.h"
#include "Network.h"

#include <random>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

namespace fcnpr{

    PandRGA::PandRGA () {
        n_generation   = MAX_GEN;
        n_populaitions = GROUP_SCALE;
        N   =   30;
        n_nodes = node_cnt();
        populations.resize(GROUP_SCALE);
    }

    uint64_t PandRGA::random_gen(uint64_t const& m) const {
        std::random_device rd;
        std::mt19937 gen (rd());
        std::uniform_int_distribution <> dis(1,m);
        uint64_t n = dis (gen);
        return n;
    }

    uint64_t PandRGA::node_cnt() {
        uint64_t cnt = 0;
        for(uint64_t i = 0; i <= network().depth(); ++i){
            cnt = cnt + network().nodes_at_level(i).size();
        }
        return cnt;
    }

    Individual PandRGA::individual_gen() {
        Individual individual;
        Position pos;
        std::vector<Position> temp_placement;
        individual.nodes_pos.clear();
        for(uint64_t i=0; i <= network().depth(); ++i){
            auto level_nodes = network().nodes_at_level(i);
            for(uint64_t j=0; j < level_nodes.size(); ++j) {
                pos.first = random_gen(N);
                pos.second = random_gen(N);
                individual.nodes_pos[level_nodes[j]] = pos;   ///在节点及对应的位置生成后，插入nodes_pos中保存。
            }
        }       ///按层级顺序生成节点的坐标，第一层节点、第二层节点....(以便于后面的处理)
        for(auto &it : individual.nodes_pos) {
            temp_placement.push_back(it.second);
        }
        individual.pos_encoded = encode(temp_placement);
        return individual;
    }

    std::vector<uint64_t> PandRGA::encode(std::vector<Position> const& placement) const {
        std::vector<uint64_t> vec;
        uint64_t val_encoded;
        for(auto & po : placement){
            val_encoded = po.first * N + po.second;
            vec.push_back(val_encoded);
        }
        return vec;
    }

    std::vector<Position> PandRGA::decode(std::vector<uint64_t> const& value) const {
        Position pos;
        std::vector<Position> pos_decode;
        for(auto & v : value ){
            pos.first  = v / N;
            pos.second = v % N;
            pos_decode.push_back(pos);
        }
        return pos_decode;
    }

    void PandRGA::initGroup() {
        std::cout << "gggggg" << std::endl;
        int n=0;
        for(auto i = 0; i< n_populaitions; ++i){
            populations.emplace_back(individual_gen()); ///该方式下，indi.node_pos中的值不存在，无法打印
            std::cout << n++ << std::endl;
        }
        /*
        for(auto i = 0; i< n_populaitions; ++i){
            auto indi = individual_gen();
            populations[i] = indi;
            std::cout << n++ << std::endl;   ///数据添加正常 但是程序异常终止
        }
        */
        for(auto i=0;i< n_populaitions; ++i){
            for(auto &item : populations[i].nodes_pos){
                std::cout<< item.first<< ":" << item.second << " " ;
            }
            std::cout << std::endl;
            for(auto &item1 : populations[i].pos_encoded){
                std::cout << item1 << " " ;
            }
            std::cout << std::endl;
        }
    }
    ///节点坐标是否有重复，重复则不满足节点位置分配要求
    bool PandRGA::containDuplicate(std::vector<uint64_t> const& vec) {
        std::cout << "uuuuu" << std::endl;
        std::unordered_set<uint64_t> set(vec.size() * 2);
        for (auto val : vec) {
            if (!set.insert(val).second) {
                return true;
            }
            return false;
        }
    }
    ///计算布局布线结果的面积，遗传算法的优化目标
    uint64_t PandRGA::area() {
        auto area = chessboard().compute_layout_area();
        return area;
    }
    ///电路存在连接关系的节点之间在分配位置后之间是否存在可行的路径,A*算法
    bool PandRGA::path_exist(Individual & individual) {
        std::cout << "bbbbb" << std::endl;
        Route route;
        for(auto i = 1; i <= network().depth(); ++i){
            auto level_node = network().nodes_at_level(i);
            for(auto it : level_node){
                std::cout << it << std::endl;
                auto fin_ins = network().fan_ins_of(it);
                for(auto &finin_node : fin_ins){
                    std::cout << finin_node <<std::endl;
                    auto pos_src = individual.nodes_pos.at(finin_node);
                    std::cout << pos_src << std::endl;
                    auto pos_tgt = individual.nodes_pos.at(it);
                    route = chessboard().compute_path_between(pos_src,pos_tgt); ///A*算法计算所有节点的路径 起始点为fininnode
                    if(route.empty()){
                        return false;                   ///遍历所有节点，若有一个节点的路径不存在则返回false
                    }else {
                        individual.routings[i].insert({std::make_pair(it, finin_node), route});///分层级缓存节点与节点之间的路径
                        for (auto &[src_tgt, route] : individual.routings[i]) {
                            std::cout << src_tgt.first << " => " << src_tgt.second << " : ";
                            for (auto &pos : route) {
                                std::cout << pos << " ";
                            }
                        std::cout << std::endl;
                        }
                    }
                }
            }
        }
        return true;
    }
    ///节点之间路径是否满足时钟同步，即两个层级节点之间的路径是否全相等
    ///首先将两层节点之间发路径缓存至一个临时的vector中，再判断这些路径的长度是否相等
    bool PandRGA::clock_sync(Individual &individual) {
        std::cout << "cccccc" << std::endl;
        std::vector<Route> temp_route;
        for (auto i = 1; i <= network().depth(); ++i) {        ///从第一层节点开始考虑  不考虑primary input节点
            auto level_node = network().nodes_at_level(i);
            for (auto it : level_node) {
                auto fin_ins = network().fan_ins_of(it);
                for (auto &finin_node : fin_ins) {
                    if(network().node_level(finin_node) == i-1){
                        temp_route.emplace_back(individual.routings[i][(std::make_pair(finin_node,it))]);
                    }                           ///判断finin_node 是不是在node的上一层级，确保node与其finin_node是相邻层级的一对节点
                    else {
                        continue;              ///若为相邻节点，则缓存路径
                    }
                }
            }
            ///路径长度判断，保证所有相邻层级节点路径长度相等
            for(auto t_r: temp_route){
                std::size_t route_length = temp_route[0].size();
                if(t_r.size() != route_length){
                    return false;
                }
            }
        }
        return true;
    }
    ///判断路径是否能正确放置实现，
    bool PandRGA::path_route(std::vector<std::unordered_map<std::pair<Node, Node>, Route>> & routings) {
        std::cout << "nnnnnn" << std::endl;
        for(auto i = 1; i <= network().depth(); ++i){
            for(auto it = routings[i].begin(); it != routings[i].end(); ++it){
                if(!chessboard().wire_route(it->second)){
                    return false;
                }
            }
        }
        return true;
    }

    bool PandRGA::place( std::map<Node,Position> const & nodes_pos) {
        std::cout << "iiiiiiii" << std::endl;
        for(auto &n_p : nodes_pos ){
            if(!chessboard().place_node(n_p.second,n_p.first)){
                return false;
            }
        }
        return true;
    }

    /*bool PandRGA::routing(std::vector<std::unordered_map<std::pair<Node, Node>, Route>> const & routings) {
        for(auto i = 1; i <= network().depth(); ++i){
            for(auto &[src_tgt,route] : routings[i]){
                if(!chessboard().wire_route(route)){
                    return false;
                }
            }
        }
        return true;
    }
    */
    void PandRGA::clear_layout(Individual & individual) {
        std::cout << "&&&&&" << std::endl;
        for (auto &n_p : individual.nodes_pos) {
            chessboard().unplace_node(n_p.second);
        }
        for(auto i = 1; i <= network().depth(); ++i) {
            for (auto &[src_tgt, route] : individual.routings[i]) {
                chessboard().wire_route(route);
            }
        }
        individual.nodes_pos.clear();
        individual.routings.clear();
    }
    ///个体适应度值的计算  若不是一个可行的解则为 1/(2*N*N) 否则为1/area()
    void PandRGA::fitness_cpt(Individual & indi) {
        std::cout << "////////////" << std::endl;
        ///遗传算法每次交叉、变异操作改变了节点的坐标位置，需要将把节点的编号与坐标位置再次统一起来
        auto real_pos = decode(indi.pos_encoded);
        int n = 0;
        for(auto &it : indi.nodes_pos){
            it.second = real_pos[n];
            ++n;
        }

        indi.fitness = 1 / (2 * N * N);
        if ((!containDuplicate(indi.pos_encoded)) && path_exist(indi)
            && clock_sync(indi) && place(indi.nodes_pos)
            && path_route(indi.routings)) {///在计算面积之前调用place、routing函数实现节点和线路的放置
            indi.fitness = 1 / area();
        }
        clear_layout(indi);    ///计算之后清除放置的节点和线路,保证只有一个chessboard类
        return;
    }
    ///遗传算法的选择  轮盘赌方案 计算每个个体被选中的概率，然后生成[0,1]之间的一个随机数决定是否被选中
    void PandRGA::selection() {
        std::cout << "*******" << std::endl;
        const double a = 0.0;
        const double b = 1.0;
        double sumfitness = 0;
        double p;
        std::vector<Individual> New_populations;
        srand ((unsigned)time(NULL));
        ///计算种群适应度之和
        for(auto i = 0; i < populations.size(); ++i ){
            sumfitness += populations[i].fitness;
            populations[i].refitness = 0;
            populations[i].cfitness = 0;
        }
        ///计算个体适应度占比
        for(auto j = 0; j < populations.size(); ++j){
            populations[j].refitness = populations[j].fitness / sumfitness;
        }
        ///计算累计适应度，即分配个体在0~1之间的位置区间
        populations[0].cfitness = populations[0].refitness;
        for(auto l =1; l < populations.size(); ++l){
            populations[l].cfitness = populations[l-1].cfitness + populations[l].refitness;
        }
        ///轮盘赌随机选择  会有一些相同个体被选中
        for(auto m = 0; m < populations.size(); ++m) {
            p = rand() % (9999 + 1) / (float)(9999 + 1);  ///定义p为[0,1]之间的一个四位小数
            if (p < populations[0].cfitness) {
                New_populations[m] = populations[0];
            }
            else {
                for (auto n = 0; n < populations.size(); ++n) {
                    if (populations[n].cfitness <= p && p < populations[n + 1].cfitness) {
                        New_populations[m] = populations[n + 1];
                    }
                }
            }
        }
        ///种群更新
        for(auto k = 0; k < populations.size(); k++){
            populations[k] = New_populations[k];
        }
        return;
    }

    ///变异算子的实现  随机生成若干个随机数作为新的位置取代原来的位置（怎么考虑电路规模不同时的变异节点的数目和突变的概率？）
    void PandRGA::mutation() {
        std::cout << ";;;;;;;;" << std::endl;
        ///  另有大变异算法 可以使算法接近完全随机化

        double a = 0.0;
        double b = 1.0;
        double p;
        srand ((unsigned)time(NULL));
        for(uint64_t i = 0; i < GROUP_SCALE; ++i){
            p =  rand() % (9999 + 1) / (float)(9999 + 1);
            if(p < 0.2){
                for(int j = 0; j < n_nodes/4; ++j){
                    int l = random_gen(n_nodes);    ///根据图的节点规模选择需要变异的位置,随机生成下标(未考虑重复)，然后用随机生成的新的值去代替旧的值
                    uint64_t x = random_gen(N);
                    uint64_t y = random_gen(N);
                    uint64_t new_pos = x * N + y;
                    populations[i].pos_encoded[l] = new_pos;
                }
            }
        }
    }
    ///交叉算子的实现 随机选择一个交叉点（下标），将0到该下标点的值（编码后的坐标值）交换
    void PandRGA::crossover() {
        std::cout << "%%%%%%%%%" << std::endl;
        std::vector<uint64_t> temp_vec(n_nodes,0);

        uint64_t x1 = random_gen(populations.size());
        uint64_t x2 = random_gen(populations.size());
        while(x1 == x2){                    ///保证交叉的两个个体是不同的个体
            x2 = random_gen(populations.size());
        }
        uint64_t point1 = random_gen(n_nodes);      ///交叉点的下标位置
        uint64_t point2 = random_gen(n_nodes);
        while(point1 == point2){                    ///保证交叉的位置是不同的位置
            point2 = random_gen(n_nodes);
        }
        int p1 = (point2 - point1) > 0 ? point1 : point2;
        int p2 = (point2 - point1) > 0 ? point2 : point1;

        for(int i = p1; i <= p2; ++i){
            temp_vec[i] = populations[x1].pos_encoded[i];
            populations[x1].pos_encoded[i] = populations[x2].pos_encoded[i];
            populations[x2].pos_encoded[i] = temp_vec[i];
        }

    }
    ///计算适应度后，选出适应度最大的一个个体（这个值不能为1/(2*N*N)）
    void PandRGA::select_the_best(){
        std::cout << "$$$$$$$$" << std::endl;
        best_indi[0] = populations[0];      ///初始化
        for(auto i = 1;i < populations.size(); ++i){
            if(best_indi[0].fitness < populations[i].fitness)           ///保留个体适应度大的个体
                best_indi[0] = populations[i];
        }
        return;
    }

    ///只有当适应度函数的值为面积的倒数时输出best_indi中的值，否则输出no solution；
    bool PandRGA::run() {
        std::cout << "+++++++++++" << std::endl;
        initGroup();
        for(auto i=0;i<n_populaitions; ++i){
            for(auto &item : populations[i].nodes_pos){
                std::cout<< item.first<< ":" << item.second << " " ;
            }
            std::cout << std::endl;
        }
        std::cout << "yyyyyyy" << std::endl;
        for(int i = 0; i < n_generation; ++i){
            for(auto j = 0; j < populations.size() ; ++j){
                std::cout << "======" << std::endl;
                fitness_cpt(populations[j]);
                std::cout << populations[j].fitness << std::endl;
            }
            select_the_best();
            selection();
            crossover();
            mutation();
        }
        return best_indi[0].fitness > 1 / (2 * N * N);
    }

    ///打印结果，将best_indi中保存的个体打印（如果存在 适应度值为area的倒数时）
    void PandRGA::pr_result() {
        auto nodes_position = decode(best_indi[0].pos_encoded);
        Node node = 1;      ///记录节点编号
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Primary Inputs: " << std::endl;

        auto n_level0 = network().nodes_at_level(0).size();
        for(auto i = 0; i < n_level0; ++i){
            std::cout <<  node << ":" << best_indi[0].nodes_pos.at(node) << std::endl;   ///节点的编号与存储下标对应
            ++node;
        }

        for(auto j = 1; j <= network().depth(); ++j) {
            std::cout << "Level " << j << std::endl;
            std::cout << "Node Positions: " << std::endl;
            for(auto k = 0 ; k < network().nodes_at_level(j).size(); ++k) {
                std::cout << node << " : " << best_indi[0].nodes_pos.at(node) << std::endl;
                ++node;
            }
            std::cout << "Routings: " << std::endl;
            for(auto &[src_tgt, route] : best_indi[0].routings[j]) {
                std::cout << src_tgt.first << " => " << src_tgt.second << " : ";
                for(auto &pos : route) {
                    std::cout << pos << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}
