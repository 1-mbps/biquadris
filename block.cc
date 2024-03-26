#include "block.h"
#include <iostream>
#include <map>

using namespace std;

Block::Block(char block_type): block_type{block_type} {
    origin_r = 3; origin_c = 1; //(0,0) on the rotation coordinate plane == (3,1) on the grid
    switch (block_type) {
        case 'I': //rotation algorithm won't work on I-block, so this is hardcoded
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
    }
    // board->add(this);
}

Block::~Block() {}

//Return a reference to avoid unnecessary copying
std::vector<std::pair<int,int>>& Block::get_coords(int inc_rotation_state) {
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

// void Block::print() {
//     for (auto p : xy_coords) {
//         std::cout << '(' << p.first << ", " << p.second << ')' << std::endl;
//     }
// }