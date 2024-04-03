#include "player.h"
#include "blind.h"

Player::~Player() {
    board.reset();
}

Player& Player::operator=(const Player& other) {
    return *this;
}

void Player::add(shared_ptr<Block> b) {
    if (b == nullptr) b = block_selector();
    // cout << "selected block " << b->get_block_type() << endl;
    board->add(b);
}

// int return is useful for Level 4
void Player::drop() {
    int rows_cleared = board->drop(); //board->drop() returns number of rows cleared
    score += rows_cleared;
    add_extra(rows_cleared); //template method
    // score += this number
}

void Player::blind() {
    board = make_shared<Blind>(board);
}

//In force, override board::add() - delete b and replace it

void Player::left() {
    board->left();
    move_modifier();
}

void Player::right() {
    board->right();
    move_modifier();
}

void Player::up() {
    board->up();
    move_modifier();
}

void Player::down() {
    board->down();
    move_modifier();
}

void Player::rotate(bool clockwise) {
    board->rotate(clockwise);
    move_modifier();
}

void Player::print() {
    cout << "Level: " << level << endl;
    cout << "Score: " << score << endl;
    board->print();
}

void Player::add_extra(int rows_cleared) {}

void Player::move_modifier() {}