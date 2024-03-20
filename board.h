#ifndef __BOARD_H__
#define __BOARD_H__
#include "observer.h"
#include <map>
#include <vector>

class Board {
    const int r = 18; //Number of rows
    const int c = 11; //Number of columns
    char grid[18][11];

    public:
        Board();
        bool is_valid(std::pair<int, int>);

        //Mark a Block's coordinates on the grid.
        void add(std::vector<std::pair<int,int>> &coords, char c);

        //Called by a Block whenever the Board needs to be updated.
        void notify(std::vector<std::pair<int,int>> &old_coords, std::vector<std::pair<int,int>> &new_coords, char c);
        
        void print(); //will keep for now, only for testing
};

#endif
