#include "game.h"

Game::Game(vector<shared_ptr<Level>> levels): levels{levels} {
    player1.set_level_class(levels[0]);
    player1.add();
    player1.right();
    player1.right();
    player1.print();
    player1.blind();
    player1.print();
    player1.right();
    player1.right();
    player1.drop();
    player1.print();
}

Game::~Game() {
    levels.clear();
}