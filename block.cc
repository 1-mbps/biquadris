#include "block.h"
#include <iostream>
#include <map>

using namespace std;

Block::Block(char block_type, int level_placed): block_type{block_type}, level_placed{level_placed} {
    origin_r = 3; origin_c = 1; //(0,0) on the rotation coordinate plane == (3,1) on the grid
    switch (block_type) {
        case 'I':
            rotations = {
                {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, //default orientation
                {{0, 0}, {-1, 0}, {-2, 0}, {-3, 0}}, //90°
                {{3, 0}, {3, 1}, {3, 2}, {3, 3}}, //180°
                {{3, 3}, {2, 3}, {1, 3}, {0, 3}} //270°
            };
            origin_c = 0;
            break;
        case 'J':
            rotations = {
                {{0, -1}, {1, -1}, {1, 0}, {1, 1}},
                {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}},
                {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}},
                {{1, 0}, {1, 1}, {0, 1}, {-1, 1}},
            };
            break;
        case 'L':
            // xy_coords = {{1, 1}, {1, 0}, {0, -1}, {-1, -1}};
            rotations = {
                {{1, -1}, {1, 0}, {1, 1}, {0, 1}},
                {{-1, -1}, {0, -1}, {1, -1}, {1, 0}},
                {{-1, 1}, {-1, 0}, {-1, -1}, {0, -1}},
                {{1, 1}, {0, 1}, {-1, 1}, {-1, 0}},
            };
            break;
        case 'O':
            rotations = {
                {{0, 0}, {0, -1}, {1, 0}, {1, -1}},
            };
            break;
        case 'S':
            rotations = {
                {{0, 0}, {0, 1}, {1, 0}, {1, -1}},
                {{0, 0}, {1, 0}, {0, -1}, {-1, -1}},
                {{0, 0}, {0, -1}, {-1, 0}, {-1, 1}},
                {{0, 0}, {-1, 0}, {0, 1}, {1, 1}},
            };
            break;
        case 'Z':
            rotations = {
                {{0, -1}, {0, 0}, {1, 0}, {1, 1}},
                {{-1, 0}, {0, 0}, {0, -1}, {1, -1}},
                {{0, 1}, {0, 0}, {-1, 0}, {-1, -1}},
                {{1, 0}, {0, 0}, {0, 1}, {-1, 1}},
            };
            break;
        case 'T':
            rotations = {
                {{0, -1}, {0, 0}, {0, 1}, {1, 0}},
                {{-1, 0}, {0, 0}, {1, 0}, {0, -1}},
                {{0, 1}, {0, 0}, {0, -1}, {-1, 0}},
                {{1, 0}, {0, 0}, {-1, 0}, {0, 1}},
            };
            break;
        case '*':
            origin_r = 3; origin_c = 5; chars_left = 1;
            rotations = {{{0,0},{0,0},{0,0},{0,0}}};
            break;
    }
    // board->add(this);
}

Block::~Block() {}

//Return a reference to avoid unnecessary copying
vector<pair<int,int>>& Block::get_coords(int inc_rotation_state) {
    int new_rs = rotation_state + inc_rotation_state;
    if (new_rs < 0) {
        new_rs = (4+new_rs);
    }
    return rotations[new_rs % 3];
}

int Block::get_origin_r() const {
    return origin_r;
}

int Block::get_origin_c() const {
    return origin_c;
}

int Block::get_rotation_state() const {
    return rotation_state;
}

char Block::get_block_type() const {
    return block_type;
}

void Block::rotate(bool clockwise) {
    if (clockwise) {
        rotation_state = (rotation_state + 1) % 3;
    } else {
        if (rotation_state == 0) {
            rotation_state = 3;
        } else {
            --rotation_state;
        }
    }
}

void Block::up() {
    --origin_r;
}

void Block::down() {
    ++origin_r;
}

void Block::left() {
    --origin_c;
}

void Block::right() {
    ++origin_c;
}

// Returns how many points a player would score after the block is changed.
// If the block has been destroyed, player gets (level+1)^2 points.
// If not, player gets 0
int Block::clear_row(int i) {
    for (auto it = rotations[rotation_state].begin(); it != rotations[rotation_state].end();) {
        if (it->first + origin_r == i) {
            rotations[rotation_state].erase(it);
            --chars_left;
        } else {
            ++it;
        }
    }
    if (chars_left == 0) return pow(level_placed+1, 2);
    return 0;
}

// void Block::print() {
//     for (auto p : xy_coords) {
//         std::cout << '(' << p.first << ", " << p.second << ')' << std::endl;
//     }
// }