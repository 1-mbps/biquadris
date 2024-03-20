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
        void add(std::vector<std::pair<int,int>> &coords, char c);
        void notify(std::vector<std::pair<int,int>> &old_coords, std::vector<std::pair<int,int>> &new_coords, char c);
        void print();
};

#endif
