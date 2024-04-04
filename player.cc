#include "player.h"
#include "actions.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

Player::~Player() {
    board.reset();
}

Player& Player::operator=(const Player& other) {
    return *this;
}

void seed_rng() {
    static bool seeded = false;
    if (seeded == false) {
        srand(time(NULL));
        seeded = true;
    }
}

void Player::add(shared_ptr<Block> b) {
    seed_rng();
    if (b == nullptr) b = block_selector();
    board->add(b);
}

void Player::drop() {
    pair<int,int> drop_values = board->drop(); //board->drop() returns number of rows cleared
    int rows_cleared = drop_values.first;
    int points_gained = drop_values.second;
    score += pow((level+rows_cleared), 2) + points_gained;
    add_extra(rows_cleared); //template method
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

void Player::print_line(int line) {
    board->print_line(line);
}

void Player::add_extra(int rows_cleared) {}

void Player::move_modifier() {}

// Accessors:

int Player::get_level() { return level; }
int Player::get_score() { return score; }