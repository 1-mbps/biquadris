#include "board.h"
#include "block.h"
#include <iostream>

using namespace std;

Board::~Board() {
    for (auto block : blocks) {
        block.reset(); //Use reset() instead of delete for smart pointers
    }
}

void Board::add(char block_type) {
    shared_ptr<Block> b(new Block(block_type));
    blocks.emplace_back(b);
    ++num_blocks;
    for (auto p : b->get_coords(0)) {
        grid[p.first+b->get_origin_r()][p.second+b->get_origin_c()] = b->get_block_type();
    }
    // b.attach(graphicsdisplay); add when implemented
}

void Board::drop() {

}

bool Board::rotate(bool clockwise) {
    if (blocks[num_blocks-1]->get_block_type() == 'O') return true;
    int inc_rotation_state = clockwise ? 1 : -1;
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
            grid[p.first+origin_r][p.second+origin_c] = ' ';
        }
        return false;
    }

    //Total running time: O(3n) = O(n)

    return true;
}

//don't keep this - this is just for testing
void Board::print() {
    cout << "Level: 1" << endl;
    cout << "Score: 0" << endl;
    cout << "-----------" << endl;
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << "-----------" << endl;
}