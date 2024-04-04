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

    // cout << "le - closest match: " << trie.return_closest_match("le") << endl;
    // cout << "lef - closest match: " << trie.return_closest_match("lef") << endl;
    // cout << "left - closest match: " << trie.return_closest_match("left") << endl;
    // cout << "lev - closest match: " << trie.return_closest_match("lev") << endl;
    // cout << "levv - closest match: " << trie.return_closest_match("levv") << endl;
    // cout << "levelup - closest match: " << trie.return_closest_match("levelup") << endl;
    // cout << "lefte - closest match: " << trie.return_closest_match("lefte") << endl;
    // cout << "wfefwewefewf - closest match: " << trie.return_closest_match("wfefew") << endl;

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
