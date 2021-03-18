//
// Created by fpeng on 2020/6/14.
//

#ifndef ROPPER_CHESSBOARD_H
#define ROPPER_CHESSBOARD_H

#include <functional>
#include <map>
#include <unordered_map>
#include <cassert>
#include <boost/container_hash/hash.hpp>

#include "Types.h"
#include "Cell.h"
#include "Astar.h"
namespace fcnpr {

    static const uint64_t DEFAULT_SIZE = 30;

    class ChessBoard {
    public:

        ChessBoard()=default;
        ~ChessBoard()=default;

        uint64_t size() const noexcept;
        void clear() noexcept;
        void resize(uint64_t sz);
        //这里是表达
        inline Cell&       cell_at(const Position &pos) noexcept {
            assert(pos.first < grid_size && pos.second < grid_size);
            return cell_grid[pos.first][pos.second];
        }
        inline Cell const& cell_at(const Position &pos) const noexcept {
            assert(pos.first < grid_size && pos.second < grid_size);
            return cell_grid[pos.first][pos.second];
        }
        inline bool is_empty_in(const Position &pos) const noexcept {
            assert(pos.first < grid_size && pos.second < grid_size);
            return cell_grid[pos.first][pos.second].empty();
        }
        inline bool has_node_in(const Position &pos) const noexcept {
            assert(pos.first < grid_size && pos.second < grid_size);
            return cell_grid[pos.first][pos.second].has_node();
        }
        bool place_node(const Position &pos, Node node) noexcept;

        void unplace_node(const Position &pos) noexcept;

        bool wire_route(const Route &wire) noexcept;

        void unwire_route(const Route &wire) noexcept;

        uint64_t compute_layout_area() const noexcept;

        Route compute_path_between(const Position &pos1, const Position &pos2);

    private:
        uint64_t  grid_size;
        std::vector<std::vector<Cell>> cell_grid;

        std::map<Coordinate, std::size_t> x_positions;
        std::map<Coordinate, std::size_t> y_positions;

        void place_callback(const Position &pos) noexcept;
        void unplace_callback(const Position &pos) noexcept;
        explicit  ChessBoard(uint64_t sz);
        friend ChessBoard& chessboard();
    };
    ChessBoard &chessboard();
}


#endif //ROPPER_CHESSBOARD_H
