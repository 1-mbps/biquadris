#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "board.h"
#include <iostream>
#include <map>
#include <vector>

class Block {

    char block_type;
    int origin_r;
    int origin_c;
    Board *board; //de facto observer
    std::vector<std::pair<int,int>> rc_coords; //actual position on the grid
    std::vector<std::pair<int,int>> xy_coords; //Coordinates of block in (x,y), relative to origin
    std::vector<std::vector<std::pair<int,int>>> rotations;
    int rotation_state;

    bool in_current_block(std::pair<int,int> p);

    public:
        Block(char block_type, Board *board);
        void rotate(bool clockwise);
        void down();
        bool update_rc_coordinates(int origin_c, int origin_r, std::vector<std::pair<int,int>> &temp);
        void print();

};

#endif
