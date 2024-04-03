#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

class Block {

    const char block_type;
    int origin_r; //r-coordinate of origin
    int origin_c; //c-coordinate of origin
    
    //Rotation orientations
    std::vector<std::vector<std::pair<int,int>>> rotations;
    int rotation_state = 0;

    const int level_placed;
    int chars_left = 4; //How many characters left. 0 -> block is destroyed

    public:
        Block(char block_type, int level_placed);
        ~Block();

        //Accessors
        int get_origin_r() const;
        int get_origin_c() const;
        int get_rotation_state() const;
        char get_block_type() const;
        std::vector<std::pair<int,int>>& get_coords(int inc_rotation_state);

        void rotate(bool clockwise); //Rotates a block. Does nothing if no space.
        void up(); //Moves a block up 1 unit.
        void down(); //Moves a block down 1 unit.
        void left();
        void right();

        int clear_row(int i); //Returns true if entire block has been cleared
        
};

#endif
