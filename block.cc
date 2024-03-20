#include "block.h"
#include <iostream>
#include <map>

using namespace std;

Block::Block(char block_type, Board *board): block_type{block_type}, board{board} {
    origin_r = 3; origin_c = 1; //(0,0) on the rotation coordinate plane == (3,1) on the grid
    switch (block_type) {
        case 'I': //rotation algorithm won't work on I-block, so this is hardcoded
            xy_coords = {{0,0}, {1,0}, {2,0}, {3,0}};
            rotations = {
                {{0,0}, {1,0}, {2,0}, {3,0}},
                {{0,0}, {0,1}, {0,2}, {0,3}},
                {{0,3}, {1,3}, {2,3}, {3,3}},
                {{3,3}, {3,2}, {3,1}, {3,0}}
            };
            origin_c = 0;
            break;
        case 'J':
            xy_coords = {{-1,0}, {-1,-1}, {0,-1}, {1,-1}}; //with (origin_r, origin_c) == (0,0) in this coordinate plane
            break;
        case 'L':
            xy_coords = {{-1,-1}, {0,-1}, {1,-1}, {1,0}};
            break;
        case 'O':
            xy_coords = {{0,0}, {-1,0}, {0,-1}, {-1,-1}};
            break;
        case 'S':
            xy_coords = {{0,0}, {1,0}, {0,-1}, {-1,-1}};
            break;
        case 'Z':
            xy_coords = {{-1,0}, {0,0}, {0,-1}, {1,-1}};
            break;
        case 'T':
            xy_coords = {{-1,0}, {0,0}, {1,0}, {0,-1}};
            break;
    }
    for (auto p : xy_coords) {
        rc_coords.emplace_back(origin_r-p.second, origin_c+p.first);
    }
    board->add(rc_coords, block_type);
}

//Rotation formula: https://en.wikipedia.org/wiki/Rotation_of_axes_in_two_dimensions
//with sin(90°) = 1 and sin(-90°) = -1
pair<int, int> rotate_cl(pair<int, int> p) {
    return make_pair(p.second, -p.first);
}

pair<int, int> rotate_ccl(pair<int, int> p) {
    return make_pair(-p.second, p.first);
}

void Block::rotate(bool clockwise) {
    std::vector<pair<int, int>> temp (4);
    if (block_type == 'O') {
        return; //rotation does nothing to the O-block
    } else if (block_type == 'I') { //I-block is an edge case
        if (clockwise) {
            ++rotation_state;
        } else {
            --rotation_state;
        }
        for (int i = 0; i < 4; ++i) {
            temp[i] = rotations[rotation_state % 3][i];
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            if (clockwise) {
                temp[i] = rotate_cl(xy_coords[i]);
            } else {
                temp[i] = rotate_ccl(xy_coords[i]);
            }
        }
    }
    update_rc_coordinates(origin_r, origin_c, temp);
}

void Block::down() {
    update_rc_coordinates(origin_r+1, origin_c, xy_coords);
}

bool Block::in_current_block(pair<int,int> p) {
    for (auto it : rc_coords) if (it == p) return true;
    return false;
}

bool Block::update_rc_coordinates(int new_r, int new_c, std::vector<std::pair<int,int>> &temp) {
    vector<pair<int, int>> temp_vec (4);
    for (int i = 0; i < 4; ++i) {
        pair<int, int> temp_pair = make_pair(new_r - temp[i].second, new_c + temp[i].first);
        if (in_current_block(temp_pair) || board->is_valid(temp_pair)) { //if valid change
            temp_vec[i] = temp_pair;
        } else {
            return false;
        }
    }
    board->notify(rc_coords, temp_vec, block_type);
    origin_r = new_r;
    origin_c = new_c;
    xy_coords = temp;
    rc_coords = temp_vec;
    return true;
}

void Block::print() {
    for (auto p : xy_coords) {
        std::cout << '(' << p.first << ", " << p.second << ')' << std::endl;
    }
}