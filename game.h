#ifndef _GAME_H_
#define _GAME_H_
#include "player.h"
#include "levels.h"
#include "trie.h"
#include <memory>

using namespace std;

// //Forward Declaration
// class Player;

class Game {
    enum Command {left, right, down, clockwise, counterclockwise, drop, levelup, leveldown, norandom,
        random, sequence, I, J, L, O, S, T, Z, restart};

    Trie trie;
    shared_ptr<Player> player1 = make_shared<Level0>();
    shared_ptr<Player> player2 = make_shared<Level0>();
    shared_ptr<Player> currPlayer = player1;

    vector<Player> levels;
    shared_ptr<GraphicsDisplay> display = nullptr;

    void print_players();

    // int sequence1;
    // int sequence2;
    // bool TextOnly;

    public:
        void executeCommand(string &command);
        void moveLeft(int multiplier);
        void moveRight(int multiplier);
        void moveDown(int multiplier);
        void rotateClockwise(int multiplier);
        void rotateCounterclockwise(int multiplier);
        void dropBlock(int multiplier);
        void levelUpByOne();
        void levelUp(int multiplier);
        void levelDownByOne();
        void levelDown(int multiplier);
        //void sequenceCommand(const string &filename);
        // void noRandom(const string& filename);
        // void random();
        // void executeSequence(const string& filename);
        // void switchBlock(const char& blockType);
        // void restart();
        Game(string sequence1, string sequence2, bool TextOnly);
        ~Game();

        //Accessors for Graphics Display
        int p1_level();
        int p2_level();
        int p1_score();
        int p2_score();
        
};

#endif
