#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "game.h"

using namespace std;

Game::Game(string sequence1, string sequence2, bool TextOnly) {
    string cmd_list[] = {"left", "right", "down", "clockwise", "counterclockwise", 
    "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart"};

    int cmd_list_length = 12;
    for (int i = 0; i < cmd_list_length; ++i) {
        trie.insert(cmd_list[i]);
    }

    player1->set_player_num(1);
    player2->set_player_num(2);

    if (TextOnly == false) {
        display = make_shared<GraphicsDisplay>();
        player1->add_window(display);
        player2->add_window(display);
    }

    player1->add();
    player2->add();
    print_players();

//     char c;
//     while (cin >> c) {
//         if (c == 'r') player1->rotate(true);
//         if (c == 'd') player1->drop();
//         if (c == 'a') player1->add();
//         if (c == 'L') player1->left();
//         if (c == 'R') player1->right();
//         if (c == 'b') player1->blind();
//         if (c == 'f') player1->force('O');
//         if (c == 'J') player1->replace_block('J');
//         if (c == 'p') print_players();
//         if (c == 'c') player1->clear_effects();
//         if (c == 'q') break;
//     }

}

Game::~Game() {
    levels.clear();
}

int getMultiplier(string &command) {
    string multiplier;
    int command_length = command.length();
    // Retrieving multiplier from command and removing it
    for (int i = 0; i < command_length; i++) {
        char curr_char = command[i];
        if (curr_char >= '2' && curr_char <= '9') {
            multiplier += curr_char;
        } else {
            command = command.substr(i, -1);
            break;
        }
    }
    // Multiplier is converted to integer
    if (multiplier.length() > 0) {
        return stoi(multiplier);
    } else {
        return 1;
    }
}

void Game::moveLeft(int multiplier) {
    while (multiplier > 0) {
        currPlayer->left();
        multiplier--;
    }
}

void Game::moveRight(int multiplier) {
    while (multiplier > 0) {
        currPlayer->right();
        multiplier--;
    }
}

void Game::moveDown(int multiplier) {
    currPlayer->down();
    while (multiplier > 0) {
        currPlayer->down();
        multiplier--;
    }
}

void Game::rotateClockwise(int multiplier) {
    while (multiplier > 0) {
        currPlayer->rotate(1);
        multiplier--;
    }     
}

void Game::rotateCounterclockwise(int multiplier) {
    while (multiplier > 0) {
        currPlayer->rotate(0);
        multiplier--;
    }
   
}

void Game::special_action() {
    cout << "Choose a special action [blind/heavy/force]: " << endl;
    string s;
    cin >> s;
    while (s != "blind" && s != "heavy" && s != "force") {
        cout << "Try again: ";
        cin >> s;
        cout << endl;
    }
    shared_ptr<Player> opponent;
    if (currPlayer == player1) {
        opponent = player2;
    } else {
        opponent = player1;
    }
    if (s == "blind") opponent->blind();
    if (s == "heavy") opponent->heavy();
    if (s == "force") {
        cout << "Choose a block type: ";
        char c;
        if (c == 'I' || c == 'J' || c == 'L' || c == 'O' || c == 'T' || c == 'Z' || c == 'S') {
            opponent->force(c);
        }
    }
}

void Game::dropBlock(int multiplier) {
    int score = currPlayer->drop();
    if (score >= 2) special_action();
    for (int i = 0; i < multiplier - 1; ++i) {
        currPlayer->add();
        score = currPlayer->drop();
        if (score >= 2) special_action();
    }
}

void Game::levelUpByOne() {
    int currLevel = currPlayer->get_level();
    if (currLevel == 0) {
        currPlayer = make_shared<Level1>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level1>(*currPlayer);
        } else {
            player2 = make_shared<Level1>(*currPlayer);
        }
    } else if (currLevel == 1) {
        currPlayer = make_shared<Level2>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level2>(*currPlayer);
        } else {
            player2 = make_shared<Level2>(*currPlayer);
        }
    } else if (currLevel == 2) {
        currPlayer = make_shared<Level3>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level3>(*currPlayer);
        } else {
            player2 = make_shared<Level3>(*currPlayer);
        }
    } else if (currLevel == 3) {
        currPlayer = make_shared<Level4>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level4>(*currPlayer);
        } else {
            player2 = make_shared<Level4>(*currPlayer);
        }
    }
}

void Game::levelUp(int multiplier) {
    while (multiplier > 0) {
        levelUpByOne();
        multiplier--;
    }
}

void Game::levelDownByOne() {
    int currLevel = currPlayer->get_level();
    if (currLevel == 2) {
        currPlayer = make_shared<Level1>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level1>(*currPlayer);
        } else {
            player2 = make_shared<Level1>(*currPlayer);
        }
    } else if (currLevel == 3) {
        currPlayer = make_shared<Level2>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level2>(*currPlayer);
        } else {
            player2 = make_shared<Level2>(*currPlayer);
        }
    } else if (currLevel == 4) {
        currPlayer = make_shared<Level3>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level3>(*currPlayer);
        } else {
            player2 = make_shared<Level3>(*currPlayer);
        }
    } else if (currLevel == 1) {
        currPlayer = make_shared<Level0>(*currPlayer);
        if (currPlayer == player1) {
            player1 = make_shared<Level0>(*currPlayer);
        } else {
            player2 = make_shared<Level0>(*currPlayer);
        }
    }
}

void Game::levelDown(int multiplier) {
    while (multiplier > 0) {
        levelDownByOne();
        multiplier--;
    }
}

// void Game::sequenceCommand(const string &filename) {

// }

void Game::executeCommand(string &cmd) {
    //get Multiplier
    int multiplier = getMultiplier(cmd);
    string getCommand = trie.return_closest_match(cmd);

    int isNotFound = getCommand.compare("NOTFOUND");
    if (isNotFound == 0) {
        return;
    } 

    if (getCommand == "left") {
        moveLeft(multiplier);
    } else if (getCommand == "right") {
        moveRight(multiplier);
    } else if (getCommand == "down") {
        moveDown(multiplier);
    } else if (getCommand == "clockwise") {
        rotateClockwise(multiplier);
    } else if (getCommand == "counterclockwise") {
        rotateCounterclockwise(multiplier);
    } else if (getCommand == "drop") {
        dropBlock(multiplier);
        // Toggle current player
        if (currPlayer == player1) {
            currPlayer = player2;
        } else {
            currPlayer = player1;
        }
        currPlayer->add();
    } else if (getCommand == "levelup") {
        levelUp(multiplier);
    } else if (getCommand == "leveldown") {
        levelDown(multiplier);
    } //else if (getCommand == "sequence") {
       // sequenceCommand("sequence.txt"); // Assuming the file name for sequence command
    //} // Add more else-if clauses for other commands
    print_players();
}

int num_digits(int n) {
    if (n < 10) return 1;
    return 1 + num_digits(n/10);
}

void Game::print_players() {
    string space = "        "; //8 spaces
    cout << "Level: " << player1->get_level() << space+"   " << "Level: " << player2->get_level() << endl;
    cout << "Score: " << player1->get_score() << space;
    
    for (int i = 0; i < 4-num_digits(player1->get_score()); ++i) cout << " ";

    cout << "Score: " << player2->get_score() << endl;
    
    cout << "-----------" << space << "-----------" << endl;
    for (int i = 0; i < 18; ++i) {
        player1->print_line(i);
        cout << space;
        player2->print_line(i);
        cout << endl;
    }
    cout << "-----------" << space << "-----------" << endl;
  
    vector<pair<int,int>> p1_next_coords = player1->get_next_coords();
    vector<pair<int,int>> p2_next_coords = player2->get_next_coords();
    char c1 = player1->get_next_block_type();
    char c2 = player2->get_next_block_type();
    char nexts[4][30];

    // cout << "got here!" << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 30; ++j) {
            nexts[i][j] = ' ';
        }
    }

    for (auto p : p1_next_coords) {
        nexts[p.first][p.second+3] = c1;
    }

    for (auto p : p2_next_coords) {
        nexts[p.first][p.second+22] = c2;
    }

    cout << "Next:" << "      "+space << "Next:" << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 30; ++j) {
            cout << nexts[i][j];
        }
        cout << endl;
    }
}
