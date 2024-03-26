#include "basicboard.h"

BasicBoard::BasicBoard() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) grid[i][j] = ' ';
    }
}

BasicBoard::~BasicBoard() {
    
}