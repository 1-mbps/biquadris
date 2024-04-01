#include "player.h"
#include "blind.h"

Player::~Player() {
    board.reset();
}

Player& Player::operator=(const Player& other) {
    return *this;
}

void Player::add() {
    shared_ptr<Block> b = block_selector();
    board->add(b);
}

void Player::drop() {
    board->drop();
}

void Player::blind() {
    board = make_shared<Blind>(board);
}

//In force, override board::add() - delete b and replace it

void Player::left() {
    board->left();
}

void Player::right() {
    board->right();
}

void Player::rotate(bool clockwise) {
    board->rotate(clockwise);
}

void Player::print() {
    board->print();
}

// testing method
void Player::do_extra() {

}