#include "basicboard.h"
#include "heavy.h"
#include "blind.h"
#include "board.h"
#include "block.h"
#include "game.h"
#include "level1.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    Game game{{make_shared<Level1>()}};
}

//This is purely for testing purposes - nowhere close to an actual harness
// int main() {

//     cout << "Board with block:" << endl << endl;
//     shared_ptr<Board> board = make_shared<BasicBoard>();
//     board->add('T');
//     board->print();
//     board->rotate(true);

//     cout << endl << "Board with block rotated clockwise" << endl << endl;
//     board->print();

//     board->rotate(false);
//     cout << endl << "Board with block rotated counterclockwise to original position and then shifted right" << endl << endl;
    
//     board->right();
//     board->right();
    
//     board->print();

//     board = make_shared<Heavy>(board);
//     board = make_shared<Blind>(board);

//     board->left();
//     board->print();

//     // block.rotate(false);
//     // block.rotate(false);
//     // block.rotate(true);

//     // block.print();

//     // pair<int, int> tl = block()
//     board.reset();

//     return 0;
// }