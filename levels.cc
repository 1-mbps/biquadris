#include "levels.h"

// <----- Level0 ----->

Level0::Level0() { board = make_shared<BasicBoard>(); }
Level0::~Level0() {}

shared_ptr<Block> Level0::block_selector() {
    shared_ptr<Block> b(new Block('I'));
    return b;
}

// <--- --->


// <----- Level1 ----->

Level1::Level1() {}
Level1::Level1(const Player &p): Player{p} {}
Level1::~Level1() {}

shared_ptr<Block> Level1::block_selector() {
    shared_ptr<Block> b(new Block('T'));
    return b;
}

// <--- --->


// <----- Level2 ----->

Level2::Level2() {}
Level2::Level2(const Player &p): Player{p} {}
Level2::~Level2() {}

shared_ptr<Block> Level2::block_selector() {
    shared_ptr<Block> b(new Block('J')); //for now - change this
    return b;
}

// <--- --->


// <----- Level3 ----->

Level3::Level3() {}
Level3::Level3(const Player &p): Player{p} {}
Level3::~Level3() {}

shared_ptr<Block> Level3::block_selector() {
    shared_ptr<Block> b(new Block('S')); //for now - change this
    return b;
}

void Level3::move_modifier() {

}


// <--- --->


// <----- Level4 ----->

// <--- --->