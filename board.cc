#include "board.h"
#include <iostream>

using namespace std;

Board::Board() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) grid[i][j] = ' ';
    }
}

bool is_within_bounds(pair<int, int> p) {
    return (0 <= p.first && p.first < 18) && (0 <= p.second && p.second < 11);
}

bool Board::is_valid(pair<int, int> p) {
    return is_within_bounds(p) && (grid[p.first][p.second] == ' ');
}

void Board::add(std::vector<std::pair<int,int>> &coords, char c) {
    for (auto p : coords) {
        grid[p.first][p.second] = c;
    }
}

void Board::notify(std::vector<std::pair<int,int>> &old_coords, std::vector<std::pair<int,int>> &new_coords, char c) {
    for (auto p : old_coords) {
        // cout << '(' << p.first << ' ' << p.second << ')' << endl;
        grid[p.first][p.second] = ' ';
    }
    cout << endl;
    for (auto p : new_coords) {
        grid[p.first][p.second] = c;
    }
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