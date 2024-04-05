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


    Game game{sequence1, sequence2, startLevel, TextOnly};
    string command;
    while (cin >> command) {
        if (command == "quit") break;
        game.executeCommand(command);
    }
    return 0;
}
