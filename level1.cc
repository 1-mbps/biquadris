#include "level1.h"

Level1::~Level1() {}

shared_ptr<Block> Level1::block_selector() {
    shared_ptr<Block> b(new Block('T'));
    return b;
}
