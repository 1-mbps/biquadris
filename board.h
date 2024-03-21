#ifndef __BOARD_H__
#define __BOARD_H__
#include "block.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Board {
    const int r = 18; //Number of rows
    const int c = 11; //Number of columns
    vector<shared_ptr<Block>> blocks;
    int num_blocks = 0;
    char grid[18][11];

    //Called by one of the rotation/translation functions whenever a block is updated.
    bool update_grid(int inc_rotation_state, int inc_r, int inc_c);

    //Checks if a coordinate (i,j) is valid.
    bool is_valid(int i, int j);

    //Checks if a coordinate (i,j) is within the bounds of the grid.
    bool is_within_bounds(int i, int j);

    public:
        Board();
        ~Board();

        //Add a block to the grid.
        void add(char block_type);

        //Rotate the block currently being edited.
        void rotate(bool clockwise);
        
        void print(); //will keep for now, only for testing
};

#endif
