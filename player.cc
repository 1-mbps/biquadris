#include "player.h"
#include "blind.h"

Player::Player() {}

Player::~Player() {
    board.reset();
}

void Player::set_level_class(shared_ptr<Level> lvl) {
    level_class = lvl;
}

void Player::add() {
    shared_ptr<Block> b = level_class->block_selector();
    board->add(b);
}

void Player::drop() {
    board->drop();
}

void Player::blind() {
    board = make_shared<Blind>(board);
}

void Player::left() {
    board->left();
}

void Player::right() {
    board->right();
}

void Player::print() {
    board->print();
}