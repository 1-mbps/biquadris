#include "game.h"
#include "trie.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {

    // string s = "left";

    // string cmd_list[] = {"left", "right", "down", "clockwise", "counterclockwise", 
    // "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart"};

    // Trie trie;
    // for (int i = 0; i < 12; ++i) trie.insert(cmd_list[i]);

    // cout << "ri - closest match: " << trie.return_closest_match("ri") << endl;
    // cout << "le - closest match: " << trie.return_closest_match("le") << endl;
    // cout << "lef - closest match: " << trie.return_closest_match("lef") << endl;
    // cout << "left - closest match: " << trie.return_closest_match("left") << endl;
    // cout << "lev - closest match: " << trie.return_closest_match("lev") << endl;
    // cout << "levelu - closest match: " << trie.return_closest_match("levelu") << endl;
    // cout << "ran - closest match: " << trie.return_closest_match("ran") << endl;
    // cout << "levv - closest match: " << trie.return_closest_match("levv") << endl;
    // cout << "levelup - closest match: " << trie.return_closest_match("levelup") << endl;
    // cout << "lefte - closest match: " << trie.return_closest_match("lefte") << endl;
    // cout << "wfefwewefewf - closest match: " << trie.return_closest_match("wfefew") << endl;
    // for (int i = 0; i < 12; ++i) {
    //     cout << cmd_list[i] << " - closest match: " << trie.return_closest_match(cmd_list[i]) << endl;
    // }

    // Game game{{Level1{}, Level2{}}};
    // Game game;
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
