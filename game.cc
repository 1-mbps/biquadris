#include "game.h"
#include "levels.h"

Game::Game() {
    // player1->add();
    // player1->right();
    // player1->right();
    // player1->rotate(true);
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->print();
    // player1 = make_shared<Level1>(*player1);
    // player1->add();
    // player1->print();
    // player1->drop();
    // player1->print();
    // player1->blind();
    // player1->print();
    // player1->right();
    // player1->right();
    // player1->drop();
    // player1->print();

    player1->add();
    player1->drop();
    player1->print();
    player1->add();
    player1->right();
    player1->right();
    player1->right();
    player1->right();
    player1->drop();
    player1->add();
    player1->drop();
    player1->print();
    player1 = make_shared<Level1>(*player1);
    player1->add();
    player1->drop();
    player1->add();
    player1->rotate(true);
    player1->rotate(true);
    for (int i = 0; i < 15; ++i) player1->right();
    player1->print();
    player1->drop();
    player1->print();
    player1 = make_shared<Level4>(*player1);
    player1->add();
    player1->drop();
    player1->print();

    //Add 5 blocks
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->blind();

    player1->print();
    // player1->add();
}

Game::~Game() {
    levels.clear();
}