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
TEST_CASE("PandR_GA.cpp testing" "[xor2.v]") {
    Network &ntk = network();
    std::string fname = std::string(TESTCASE) + "/xor2.v";
    ntk.parse(fname);

    auto pandr = PandRGA();
    if(pandr.run()) {
        pandr.pr_result();
    } else {
        std::cout << "No solution." << std::endl;
    }
}

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