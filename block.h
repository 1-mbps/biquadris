#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "board.h"
#include <iostream>
#include <map>
#include <vector>

class Block {

    char block_type;
    int origin_r; //r-coordinate of origin
    int origin_c; //c-coordinate of origin
    Board *board; //de facto observer
    
    //Coordinates of each point on the (r,c) plane, which is what the grid uses
    std::vector<std::pair<int,int>> rc_coords;
    
    //Coordinates of block in (x,y), relative to a chosen origin.
    //We need this in (x,y) because rotation is done around a point in (x,y)
    std::vector<std::pair<int,int>> xy_coords;
    
    //for rotating the I-block (edge case) - otherwise blank
    std::vector<std::vector<std::pair<int,int>>> rotations;
    int rotation_state;

    //Helper function that says whether a coordinate pair is part of a block
    bool in_current_block(std::pair<int,int> p);

    public:
        Block(char block_type, Board *board);
        void rotate(bool clockwise);
        void down();
        bool update_rc_coordinates(int origin_c, int origin_r, std::vector<std::pair<int,int>> &temp);
        void print();

};

#endif
