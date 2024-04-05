#include "game.h"
#include "trie.h"
#include <iostream>
#include <memory>
#include "window.h"

using namespace std;

int main(int argc, char* argv[]) {

    string sequence1 = "sequence1.txt";
    string sequence2 = "sequence2.txt";

    int startLevel = 0;
    bool TextOnly = false;
    int seed = 1;

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            string input = argv[i];
            if (input == "-text") {
                TextOnly = true;
            } else if (input == "-seed") {
                seed = stoi(argv[i+1]);
                ++i;
            } else if (input == "-scriptfile1") {
                sequence1 = argv[i+1];
                ++i;
            } else if (input == "-scriptfile2") {
                sequence2 = argv[i+1];
                ++i;
            } else if (input == "-startlevel") {
                startLevel = stoi(argv[i+1]);
                ++i;
            } else {
                cerr << "Invalid Command Line Argument " << input << endl;
            }
        }
    }

// Game g(sequence1, sequence2, TextOnly);

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
    Game game{sequence1, sequence2, TextOnly};
    string command;
    while (cin >> command) {
        if (command == "quit") break;
        game.executeCommand(command);
    }
    return 0;
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
