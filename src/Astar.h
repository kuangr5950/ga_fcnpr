//
// Created by rkuang on 2020/12/13.
//

#ifndef FCNPR_ASTAR_H
#define FCNPR_ASTAR_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Types.h"

namespace fcnpr{

    typedef struct Point {
        uint64_t x, y;
        int g;
        int h;
        int f;
        Point *father;
        Point(uint64_t const &x, uint64_t const &y) {
            this->x = x;
            this->y = y;
            this->g = 0;
            this->h = 0;
            this->f = 0;
            this->father = NULL;
        }
        Point(uint64_t const &x, uint64_t const &y, Point *father) {
            this->x = x;
            this->y = y;
            this->g = 0;
            this->h = 0;
            this->f = 0;
            this->father = father;
        }
    } Point;

    class Astar {
    public:
        Astar()=default;
        ~Astar()=default;

        void search(Position const &pos1, Position const &pos2);//搜索路径

        void checkPoint(uint64_t x, uint64_t y, Point *father, int g);//检查周围结点

        void NextStep(Point *currentPoint);//下一个合适的结点

        uint64_t isContains(std::vector<Point *> *Pointlist, uint64_t x, uint64_t y);

        void countGHF(Point *sPoint, Point *ePoint, int g);

        static bool compare(Point *p1, Point *p2);

        bool unWalk(uint64_t const &x1, uint64_t const &y1, uint64_t const &x, const uint64_t &y);

        uint8_t time_zone_of(Position const &pos);

        void Path_cache(Point *current);

        std::vector<Point *> openList;
        std::vector<Point *> closeList;
        std::vector<Position> route;

        Point *startPos;
        Point *endPos;

        static const int wayCost{10};
        static const uint64_t row{30};
        static const uint64_t col{30};
    };
}
#endif //FCNPR_ASTAR_H
