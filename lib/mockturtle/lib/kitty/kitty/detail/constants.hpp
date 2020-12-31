/* kitty: C++ truth table library
 * Copyright (C) 2017-2018  EPFL
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

/*!
  \file constants.hpp
  \brief Collects several important constants

  \author Mathias Soeken
*/

/*! \cond PRIVATE */
#pragma once

#include <cstdint>
#include <vector>

namespace kitty
{

namespace detail
{

static constexpr uint64_t projections[] = {
    UINT64_C( 0xaaaaaaaaaaaaaaaa ),
    UINT64_C( 0xcccccccccccccccc ),
    UINT64_C( 0xf0f0f0f0f0f0f0f0 ),
    UINT64_C( 0xff00ff00ff00ff00 ),
    UINT64_C( 0xffff0000ffff0000 ),
    UINT64_C( 0xffffffff00000000 )};

static constexpr uint64_t projections_neg[] = {
    UINT64_C( 0x5555555555555555 ),
    UINT64_C( 0x3333333333333333 ),
    UINT64_C( 0x0f0f0f0f0f0f0f0f ),
    UINT64_C( 0x00ff00ff00ff00ff ),
    UINT64_C( 0x0000ffff0000ffff ),
    UINT64_C( 0x00000000ffffffff )};

static constexpr uint64_t masks[] = {
    UINT64_C( 0x0000000000000001 ),
    UINT64_C( 0x0000000000000003 ),
    UINT64_C( 0x000000000000000f ),
    UINT64_C( 0x00000000000000ff ),
    UINT64_C( 0x000000000000ffff ),
    UINT64_C( 0x00000000ffffffff ),
    UINT64_C( 0xffffffffffffffff )};

static constexpr uint64_t permutation_masks[][3] = {
    {UINT64_C( 0x9999999999999999 ), UINT64_C( 0x2222222222222222 ), UINT64_C( 0x4444444444444444 )},
    {UINT64_C( 0xc3c3c3c3c3c3c3c3 ), UINT64_C( 0x0c0c0c0c0c0c0c0c ), UINT64_C( 0x3030303030303030 )},
    {UINT64_C( 0xf00ff00ff00ff00f ), UINT64_C( 0x00f000f000f000f0 ), UINT64_C( 0x0f000f000f000f00 )},
    {UINT64_C( 0xff0000ffff0000ff ), UINT64_C( 0x0000ff000000ff00 ), UINT64_C( 0x00ff000000ff0000 )},
    {UINT64_C( 0xffff00000000ffff ), UINT64_C( 0x00000000ffff0000 ), UINT64_C( 0x0000ffff00000000 )}};

static constexpr uint64_t ppermutation_masks[][6][3] = {
    {{UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x9999999999999999 ), UINT64_C( 0x2222222222222222 ), UINT64_C( 0x4444444444444444 )},
     {UINT64_C( 0xa5a5a5a5a5a5a5a5 ), UINT64_C( 0x0a0a0a0a0a0a0a0a ), UINT64_C( 0x5050505050505050 )},
     {UINT64_C( 0xaa55aa55aa55aa55 ), UINT64_C( 0x00aa00aa00aa00aa ), UINT64_C( 0x5500550055005500 )},
     {UINT64_C( 0xaaaa5555aaaa5555 ), UINT64_C( 0x0000aaaa0000aaaa ), UINT64_C( 0x5555000055550000 )},
     {UINT64_C( 0xaaaaaaaa55555555 ), UINT64_C( 0x00000000aaaaaaaa ), UINT64_C( 0x5555555500000000 )}},
    {{UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0xc3c3c3c3c3c3c3c3 ), UINT64_C( 0x0c0c0c0c0c0c0c0c ), UINT64_C( 0x3030303030303030 )},
     {UINT64_C( 0xcc33cc33cc33cc33 ), UINT64_C( 0x00cc00cc00cc00cc ), UINT64_C( 0x3300330033003300 )},
     {UINT64_C( 0xcccc3333cccc3333 ), UINT64_C( 0x0000cccc0000cccc ), UINT64_C( 0x3333000033330000 )},
     {UINT64_C( 0xcccccccc33333333 ), UINT64_C( 0x00000000cccccccc ), UINT64_C( 0x3333333300000000 )}},
    {{UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0xf00ff00ff00ff00f ), UINT64_C( 0x00f000f000f000f0 ), UINT64_C( 0x0f000f000f000f00 )},
     {UINT64_C( 0xf0f00f0ff0f00f0f ), UINT64_C( 0x0000f0f00000f0f0 ), UINT64_C( 0x0f0f00000f0f0000 )},
     {UINT64_C( 0xf0f0f0f00f0f0f0f ), UINT64_C( 0x00000000f0f0f0f0 ), UINT64_C( 0x0f0f0f0f00000000 )}},
    {{UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0xff0000ffff0000ff ), UINT64_C( 0x0000ff000000ff00 ), UINT64_C( 0x00ff000000ff0000 )},
     {UINT64_C( 0xff00ff0000ff00ff ), UINT64_C( 0x00000000ff00ff00 ), UINT64_C( 0x00ff00ff00000000 )}},
    {{UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 ), UINT64_C( 0x0000000000000000 )},
     {UINT64_C( 0xffff00000000ffff ), UINT64_C( 0x00000000ffff0000 ), UINT64_C( 0x0000ffff00000000 )}}};

static constexpr int32_t hex_to_int[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
                                         -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

/*! adjacent swap sequences (from 2 to 6 variables) */
static std::vector<uint8_t> swaps[] = {{0},
                                       {1, 0, 1, 0, 1},
                                       {2, 1, 0, 2, 0, 1, 2, 0, 2, 1, 0, 2, 0, 1, 2, 0, 2, 1, 0, 2, 0, 1, 2},
                                       {3, 2, 1, 0, 3, 0, 1, 2, 3, 1, 3, 2, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 1, 0, 1, 0, 1, 2, 3, 1, 3, 2, 1, 0, 3, 0, 1, 2, 3, 0, 3, 2, 1, 0, 3, 0, 1, 2, 3, 1, 3, 2, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 1, 0, 1, 0, 1, 2, 3, 1, 3, 2, 1, 0, 3, 0, 1, 2, 3, 0, 3, 2, 1, 0, 3, 0, 1, 2, 3, 1, 3, 2, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 1, 0, 1, 0, 1, 2, 3, 1, 3, 2, 1, 0, 3, 0, 1, 2, 3},
                                       {4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 1, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 1, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 1, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 1, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 1, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 1, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4, 0, 4, 3, 2, 1, 0, 2, 0, 1, 2, 3, 4, 2, 4, 3, 2, 1, 0, 4, 0, 1, 2, 3, 4}};

/*! flip sequences (from 2 to 6 variables) */
static std::vector<uint8_t> flips[] = {{0, 1, 0},
                                       {0, 1, 0, 2, 0, 1, 0},
                                       {0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0},
                                       {0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0},
                                       {0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0}};

static constexpr uint8_t de_bruijn64[] = {63, 0, 58, 1, 59, 47, 53, 2,
                                          60, 39, 48, 27, 54, 33, 42, 3,
                                          61, 51, 37, 40, 49, 18, 28, 20,
                                          55, 30, 34, 11, 43, 14, 22, 4,
                                          62, 57, 46, 52, 38, 26, 32, 41,
                                          50, 36, 17, 19, 29, 10, 13, 21,
                                          56, 45, 25, 31, 35, 16, 9, 12,
                                          44, 24, 15, 8, 23, 7, 6, 5};

} // namespace detail
} // namespace kitty
/*! \endcond */
