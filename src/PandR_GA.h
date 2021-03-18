//
// Created by rkuang on 2020/12/27.
//

#ifndef FCNPR_PANDR_GA_H
#define FCNPR_PANDR_GA_H

#include <vector>
#include <unordered_map>
#include <random>
#include <map>
#include "ChessBoard.h"
#include "Network.h"
#include <stdlib.h>
#include <ctime>
#include <algorithm>

#include "Types.h"
namespace fcnpr {
    //一个个体就是一个电路的布线位置
    struct Individual {
        std::vector<uint64_t> pos_encoded;     ///位置坐标被编码后的布局
        //有问题
        std::map<Node,Position> nodes_pos;   ///各节点以及对应的位置 map中不允许有重复的key值元素
        std::vector<std::unordered_map<std::pair<Node, Node>, Route>> routings;   ///保存节点之间的可行路径(不用编码)
        double fitness = 0.0;                 ///适应度值
        double refitness = 0.0;               ///累加值
        double cfitness = 0.0;                ///用于辅助计算适应度占比和被选中概率等
    };

    static const uint64_t GROUP_SCALE{100} ;
    static const uint64_t MAX_GEN{500};
    static const double P_MUTATION{0.2};
    static const double P_CROSSOVER{0.8};

    class PandRGA {
    public:
        PandRGA();
        bool run();
        void pr_result();

        uint64_t  random_gen(uint64_t const& m) const;
        std::vector<uint64_t> encode(std::vector<Position> const& placement) const;
        std::vector<Position> decode(std::vector<uint64_t> const& value) const;
        Individual individual_gen();
        void initGroup();
        bool containDuplicate(std::vector<uint64_t> const& vec);
        uint64_t node_cnt();
        uint64_t area();        ///面积计算
        bool path_exist(Individual & individual);      ///根据连接关系的两个节点之间的路径是否存在
        bool clock_sync(Individual &individual);      ///节点的放置和路径对否满足时钟同步
        bool path_route(std::vector<std::unordered_map<std::pair<Node, Node>, Route>> & routings);     ///存在的路径是否可以正确连接
        void clear_layout(Individual & individual);

        void fitness_cpt(Individual & individual);
        void crossover();
        void selection();
        void mutation();
        void select_the_best();

        ~PandRGA()=default;
    private:
        std::vector<Position> placement;     ///节点的具体位置
        uint64_t N;                  ///网格大小
        uint64_t n_populaitions;     ///种群规模
        uint64_t n_generation;       ///迭代次数
        uint64_t n_nodes;            ///节点个数
        std::vector<Individual*> populations;    ///种群
        std::vector<Individual*> best_indi;  ///保存最优个体
    };
}
#endif //FCNPR_PANDR_GA_H
