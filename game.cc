#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "game.h"
//#include "levels.h"
//#include "player.h"

using namespace std;

Game::Game(string sequence1, string sequence2, bool TextOnly) {
    string cmd_list[] = {"left", "right", "down", "clockwise", "counterclockwise", 
    "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart"};

    int cmd_list_length = 12;
    for (int i = 0; i < cmd_list_length; ++i) {
        // cout << cmd_list[i] << endl;
        trie.insert(cmd_list[i]);
    }

    // trie.insert("left");
    // trie.insert("")
    // player1->add();
    // player1->drop();
    // player2->add();
    // player2->drop();
    // print_players();
    // player1->add();
    // player1->right();
    // player1->right();
    // player1->right();
    // player1->right();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // print_players();
    // player1 = make_shared<Level1>(*player1);
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->rotate(true);
    // player1->rotate(true);
    // for (int i = 0; i < 15; ++i) player1->right();
    // print_players();
    // player1->drop();
    // print_players();
    // player1 = make_shared<Level4>(*player1);
    // player1->add();
    // player1->drop();
    // print_players();

    // //Add 5 blocks
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->blind();

    // print_players();
    
    // // On design document, write "fields are the same, so no need to overload copy assignment operator"
    // player2 = make_shared<Level4>(*player2);
    // player2->add();
    // player2->drop();
    // player2 = make_shared<Level0>(*player2);
    // player2->add();
    // print_players();

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

void Game::dropBlock(int multiplier) {
    currPlayer->drop();
    for (int i = 0; i < multiplier - 1; ++i) {
        currPlayer->add();
        currPlayer->drop();
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
    cout << getCommand;

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
    } else if (getCommand == "levelup") {
        levelUp(multiplier);
    } else if (getCommand == "leveldown") {
        levelDown(multiplier);
    } //else if (getCommand == "sequence") {
       // sequenceCommand("sequence.txt"); // Assuming the file name for sequence command
    //} // Add more else-if clauses for other commands
}

int num_digits(int n) {
    if (n < 10) return 1;
    return 1 + num_digits(n/10);
}

void Game::print_players() {
    string space = "        ";
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
}