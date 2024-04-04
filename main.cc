#include "basicboard.h"
#include "actions.h"
#include "actions.h"
#include "board.h"
#include "block.h"
#include "game.h"
#include "trie.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {

    // string s = "left";

    // Trie trie;
    // trie.insert(s);
    // trie.insert("level");

    // if (trie.in_trie(s)) { cout << "Found " << s << endl; }
    // if (trie.in_trie("le")) { cout << "Found le!" << endl; }
    // if (trie.in_trie("lef")) { cout << "Found lef!" << endl; }
    // if (trie.in_trie("lev")) { cout << "Found lev!" << endl; }
    // if (trie.in_trie("lefte")) { cout << "Found lefte!" << endl; }
    // if (trie.in_trie("feiofjowfjwef")) { cout << "Found feiofjowfjwef!" << endl; }

    // Game game{{Level1{}, Level2{}}};
    Game game;
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
