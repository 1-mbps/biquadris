#include "game.h"
#include "level2.h"

Game::Game() {
    player1->add();
    player1->right();
    player1->right();
    player1->rotate(true);
    player1->drop();
    player1->add();
    player1->drop();
    player1->print();
    player1 = make_shared<Level2>(*player1);
    player1->add();
    player1->do_extra(); //do_extra() is a placeholder function to test if the overriding works
    player1->print();
    // player1->blind();
    // player1->print();
    // player1->right();
    // player1->right();
    // player1->drop();
    // player1->print();
}

Game::~Game() {
    levels.clear();
}