#include "levels.h"

// <----- Level0 ----->

Level0::Level0() {
    board = make_shared<BasicBoard>();
    next = block_selector();
}

Level0::Level0(const Player &p): Player{p} { update_level(0); }

Level0::~Level0() {}

shared_ptr<Block> Level0::block_selector() {
    shared_ptr<Block> b(new Block('I', 0)); //for now - change later
    return b;
}

// <--- --->


// <----- Level1 ----->

Level1::Level1() { next = block_selector(); }
Level1::Level1(const Player &p): Player{p} { update_level(1); }
Level1::~Level1() {}

shared_ptr<Block> Level1::block_selector() {
    shared_ptr<Block> b(new Block('T', 1)); //for now - change later
    return b;
}

// <--- --->


// <----- Level2 ----->

Level2::Level2() { next = block_selector(); }
Level2::Level2(const Player &p): Player{p} { update_level(2); }
Level2::~Level2() {}

shared_ptr<Block> Level2::block_selector() {
    char block_type = selections[rand() % 7];
    shared_ptr<Block> b(new Block(block_type, 2));
    return b;
}

// <--- --->


// <----- Level3 ----->

Level3::Level3() { next = block_selector(); }
Level3::Level3(const Player &p): Player{p} { update_level(3); }
Level3::~Level3() {}

shared_ptr<Block> Level3::block_selector() {
    char block_type = selections[rand() % 9];
    shared_ptr<Block> b(new Block(block_type, 3));
    return b;
}

void Level3::move_modifier() {
    down();
}

// <--- --->


// <----- Level4 ----->

Level4::Level4() { next = block_selector(); }
Level4::Level4(const Player &p): Player{p} { update_level(4); }
Level4::~Level4() {}

shared_ptr<Block> Level4::block_selector() {
    char block_type = selections[rand() % 9];
    shared_ptr<Block> b(new Block(block_type, 4));
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