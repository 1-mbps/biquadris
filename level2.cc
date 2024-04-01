#include "level2.h"

Level2::Level2() {}

Level2::Level2(const Player &p): Player{p} {}

Level2::~Level2() {}

shared_ptr<Block> Level2::block_selector() {
    shared_ptr<Block> b(new Block('J')); //for now - change this
    return b;
}

void Level2::do_extra() {
    cout << "did extra!" << endl;
}
