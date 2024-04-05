#include "board.h"
#include "block.h"
#include <iostream>

using namespace std;

Board::~Board() {
    for (auto block : blocks) {
        block.reset(); //Use reset() instead of delete for smart pointers
    }
}

void Board::add(shared_ptr<Block> b) {
    blocks.emplace_back(b);
    ++num_blocks;
    for (auto p : b->get_coords(0)) {
        grid[p.first+b->get_origin_r()][p.second+b->get_origin_c()] = b->get_block_type();
    }
    // b.attach(graphicsdisplay); add when implemented
}

pair<int,int> Board::drop() {
    bool can_go_down = true;
    while (can_go_down) {
        can_go_down = down();
    }
    int origin_r = blocks[num_blocks-1]->get_origin_r();
    // int origin_c = blocks[num_blocks-1]->get_origin_c();
    vector<pair<int,int>> coords = blocks[num_blocks-1]->get_coords(0);
    int min_r = 0; int max_r = 0;

    // Get upper and lower bounds of block
    for (auto p : coords) {
        if (p.first < min_r) min_r = p.first;
        if (p.first > max_r) max_r = p.first;
    }

    int rows_cleared = 0;
    int points_gained = 0;

    for (int i = min_r+origin_r; i <= max_r+origin_r; ++i) {
        if (is_full(i)) {
            points_gained += clear_row(i);
            ++rows_cleared;
        }
    }

    if (rows_cleared != 0) recalibrate_grid(rows_cleared);

    return make_pair(rows_cleared, points_gained);
}

void Board::recalibrate_grid(int rows_cleared) {

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            grid[i][j] = ' ';
        }
    }

    // cout << "num blocks: " << num_blocks << endl;

    for (auto block : blocks) {

        for (int i = 0; i < rows_cleared; ++i) block->down();

        int origin_r = block->get_origin_r();
        int origin_c = block->get_origin_c();
        char c = block->get_block_type();
        vector<pair<int,int>> coords = block->get_coords(0); //These are references - no unnecessary copying

        for (auto p : coords) {
            grid[p.first+origin_r][p.second+origin_c] = c;
        }
    }
}

// <--- Block movement --->

bool Board::rotate(bool clockwise) {
    if (blocks[num_blocks-1]->get_block_type() == 'O') return true;
    int inc_rotation_state = clockwise ? 1 : -1;
    //update_grid returns bool corresponding to whether move is valid
    if (update_grid(inc_rotation_state, 0, 0)) {
        blocks[num_blocks-1]->rotate(clockwise);
        return true;
    }
    return false;
}

bool Board::up() {
    if (update_grid(0, -1, 0)) {
        blocks[num_blocks-1]->up();
        return true;
    }
    return false;
}

bool Board::down() {
    if (update_grid(0, 1, 0)) {
        blocks[num_blocks-1]->down();
        return true;
    }
    return false;
}

bool Board::left() {
    if (update_grid(0, 0, -1)) {
        blocks[num_blocks-1]->left();
        return true;
    }
    return false;
}

bool Board::right() {
    if (update_grid(0, 0, 1)) {
        blocks[num_blocks-1]->right();
        return true;
    }
    return false;
}

// < --- >


// <--- Helper functions for update_grid() --->

bool in_current_block(vector<pair<int,int>> &old_coords, pair<int,int> p) {
    for (auto it : old_coords) if (it == p) return true;
    return false;
}

bool Board::is_within_bounds(int i, int j) {
    return (0 <= i && i < r) && (0 <= j && j < c);
}

bool Board::is_valid(int i, int j) {
    return is_within_bounds(i, j) && (grid[i][j] == ' ');
}

// < --- >

bool Board::update_grid(int inc_rotation_state, int inc_r, int inc_c) {
    int origin_r = blocks[num_blocks-1]->get_origin_r();
    int origin_c = blocks[num_blocks-1]->get_origin_c();
    char c = blocks[num_blocks-1]->get_block_type();
    vector<pair<int,int>> old_coords = blocks[num_blocks-1]->get_coords(0); //These are references - no unnecessary copying
    vector<pair<int,int>> new_coords = blocks[num_blocks-1]->get_coords(inc_rotation_state);

    //Let n be the number of characters in a block.
    //Clear the old coordinates - O(n)
    for (auto p : old_coords) {
        grid[p.first+origin_r][p.second+origin_c] = ' ';
    }

    bool valid = true;
    
    // Check if new coordinates are valid - O(n)
    for (auto p : new_coords) {
        int i = p.first+origin_r+inc_r;
        int j = p.second+origin_c+inc_c;
        if (is_valid(i,j) == false) valid = false;
    }

    if (valid) {
        // mark the new coordinates - O(n)
        for (auto p : new_coords) {
            grid[p.first+origin_r+inc_r][p.second+origin_c+inc_c] = c;
        }
    } else {
        // restore the old coordinates - O(n)
        for (auto p : old_coords) {
            grid[p.first+origin_r][p.second+origin_c] = c;
        }
        return false;
    }

    //Total running time: O(3n) = O(n)

    return true;
}

char Board::get_point(int i, int j) {
    return grid[i][j];
}

bool Board::is_full(int i) {
    for (int j = 0; j < c; ++j) if (grid[i][j] == ' ') return false;
    return true;
}

int Board::clear_row(int i) {
    int points_gained = 0;
    for (auto block : blocks) {
        points_gained += block->clear_row(i);
    }
    return points_gained;
}

void Board::print_line(int line) {
    for (int j = 0; j < 11; ++j) {
        cout << grid[line][j];
    }
}

void Board::update_level(int new_level) {
    level = new_level;
}

int Board::get_level() const {
    return level;
}