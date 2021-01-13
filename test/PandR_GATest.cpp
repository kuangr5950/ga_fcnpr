//
// Created by rkuang on 2020/12/31.
//

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#define private public

#include "ChessBoard.h"
#include "Network.h"
#include "PandR_GA.h"
#include <iostream>

using namespace fcnpr;
using namespace Catch;

TEST_CASE("PandR_GA.cpp testing" "[c17.v]") {
    ///函数功能测试
    Network &ntk = network();
    std::string fname = std::string(TESTCASE) + "/c17.v";
    ntk.parse(fname);

    auto pandr = PandRGA();

    ///数据成员的赋值
    std::cout << pandr.N <<std::endl;
    std::cout << pandr.n_populaitions << std::endl;
    std::cout << pandr.n_generation << std::endl;
    std::cout << pandr.n_nodes << std::endl;

    Individual indi = pandr.individual_gen();
    for(auto &item : indi.nodes_pos){
        std::cout<< item.first << ":" << item.second << " " ;
    }
    std::cout << std::endl;
    for(auto &item1 : indi.pos_encoded){
        std::cout << item1 << " " ;
    }
    std::cout << std::endl;

    /*
    pandr.initGroup();
    for(auto i=0;i< pandr.n_populaitions; ++i){
        for(auto &item : pandr.populations[i].nodes_pos){
            std::cout<< item.first<< ":" << item.second << " " ;
        }
        std::cout << std::endl;
        for(auto &item1 : pandr.populations[i].pos_encoded){
            std::cout << item1 << " " ;
        }
        std::cout << std::endl;
    }
    */



    if(pandr.run()) {
        pandr.pr_result();
    } else {
        std::cout << "No solution." << std::endl;
    }
}
/*
TEST_CASE("Astar testing" "[astar]") {

    ChessBoard &cbd = chessboard();
    Position p1(3,3);
    Position p2(4,3);

    std::cout << p1 << std::endl;
    Route route = cbd.compute_path_between(p1,p2);
    std::cout << route.size() << std::endl;
    for(auto &pos : route) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    Position p3(2,3);
    Position p4(5,3);

    std::cout << p1 << std::endl;
    Route route1 = cbd.compute_path_between(p3,p4);
    std::cout << route.size() << std::endl;
    for(auto &p : route1) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
}
*/
/*
TEST_CASE("PandR_GA.cpp testing" "[c17.v]") {
    Network &ntk = network();
    std::string fname = std::string(TESTCASE) + "/c17.v";
    ntk.parse(fname);

    auto pandr = PandRGA();
    if(pandr.run()) {
        pandr.pr_result();
    } else {
        std::cout << "No solution." << std::endl;
    }
}
*/
/*
TEST_CASE("PandR_GA.cpp testing" "[xor2.v]") {
    Network &ntk = network();
    std::cout << "mmmmmm" << std::endl;
    std::string fname = std::string(TESTCASE) + "/xor2.v";
    ntk.parse(fname);

    auto pandr = PandRGA();
    std::cout << "lllll" << std::endl;
    if(pandr.run()) {
        std::cout << "xxxx" << std::endl;
        pandr.pr_result();
    } else {
        std::cout << "No solution." << std::endl;
    }
}
*/
/*
TEST_CASE("PandR_TopoOrder.cpp testing" "[1bitAdderMaj.v]") {
    Network &ntk = network();
    std::string fname = std::string(TESTCASE) + "/1bitAdderMaj.v";
    ntk.parse(fname);

    auto pandr = PandRGA();
    if(pandr.run()) {
        pandr.pr_result();
    } else {
        std::cout << "No solution." << std::endl;
    }
}
*/
/*
TEST_CASE("PandR_GA.cpp testing" "[1bitAdderAOIG.v]") {
    Network &ntk = network();
    std::string fname = std::string(TESTCASE) + "/1bitAdderAOIG.v.v";
    ntk.parse(fname);

    auto pandr = PandRGA();
    if(pandr.run()) {
        pandr.pr_result();
    } else {
        std::cout << "No solution." << std::endl;
    }
}
*/
/*
TEST_CASE("PandR_GA.cpp testing" "[mux21.v]") {
    Network &ntk = network();
    std::string fname = std::string(TESTCASE) + "/mux21.v.v";
    ntk.parse(fname);

    auto pandr = PandRGA();
    if(pandr.run()) {
        pandr.pr_result();
    } else {
        std::cout << "No solution." << std::endl;
    }
}
*/