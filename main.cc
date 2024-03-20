#include "block.h"
#include <iostream>

using namespace std;

//This is purely for testing purposes - nowhere close to an actual harness
int main() {

    cout << "Board with block:" << endl << endl;
    Board board = Board{};
    Block block = Block{'T', &board}; //works for all blocks
    board.print();
    block.rotate(true);

    cout << endl << "Board with block rotated clockwise" << endl << endl;
    board.print();

    block.rotate(false);
    cout << endl << "Board with block rotated counterclockwise to original position" << endl << endl;
    board.print();

    // block.rotate(false);
    // block.rotate(false);
    // block.rotate(true);

    // block.print();

    // pair<int, int> tl = block()

    return 0;
}
