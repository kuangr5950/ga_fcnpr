//
// Created by fpeng on 2020/6/22.
//

#ifndef FCNPR_TYPES_H
#define FCNPR_TYPES_H

//#include <utility>
#include <vector>
#include <set>
#include <iostream>
//#include <boost/container_hash/hash.hpp>
using namespace std;
namespace fcnpr
{
    using Node       = uint64_t ;
    using Coordinate = uint64_t;
    using Position   = std::pair<Coordinate, Coordinate>;
    using Route      = std::vector<Position>;
    using Region     = std::set<Position>;
    using TimeZone   = uint8_t;
    using Level      = uint32_t;
}

//#endif
#endif //ROPPER_TYPES_H
