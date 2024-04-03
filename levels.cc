#include "levels.h"

// <----- Level0 ----->

Level0::Level0() { board = make_shared<BasicBoard>(); }
Level0::~Level0() {}

shared_ptr<Block> Level0::block_selector() {
    shared_ptr<Block> b(new Block('I', 0));
    return b;
}

// <--- --->


// <----- Level1 ----->

Level1::Level1() {}
Level1::Level1(const Player &p): Player{p} {}
Level1::~Level1() {}

shared_ptr<Block> Level1::block_selector() {
    shared_ptr<Block> b(new Block('T', 1));
    return b;
}

// <--- --->


// <----- Level2 ----->

Level2::Level2() {}
Level2::Level2(const Player &p): Player{p} {}
Level2::~Level2() {}

shared_ptr<Block> Level2::block_selector() {
    shared_ptr<Block> b(new Block('J', 2)); //for now - change this
    return b;
}

// <--- --->


// <----- Level3 ----->

Level3::Level3() {}
Level3::Level3(const Player &p): Player{p} {}
Level3::~Level3() {}

shared_ptr<Block> Level3::block_selector() {
    shared_ptr<Block> b(new Block('S', 3)); //for now - change this
    return b;
}

void Level3::move_modifier() {
    down();
}

// <--- --->


// <----- Level4 ----->

Level4::Level4() {}
Level4::Level4(const Player &p): Player{p} {}
Level4::~Level4() {}

shared_ptr<Block> Level4::block_selector() {
    shared_ptr<Block> b(new Block('S', 4)); //for now - change this
    return b;
}

void Level4::add_extra(int rows_cleared) {
    if (rows_cleared == 0) {
        ++moves_since_last_clear;
    } else {
        moves_since_last_clear = 0;
    }
    if (moves_since_last_clear % 5 == 0) {
        shared_ptr<Block> b(new Block('*', 4));
        add(b);
        drop();
    }
}

void Level4::move_modifier() {
    down();
}

// <--- --->