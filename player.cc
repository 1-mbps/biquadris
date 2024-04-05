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
    if (b == nullptr) b = next;
    board->add(b);
    next = block_selector();
    board->display_next(next);
}

int Player::drop() {
    pair<int,int> drop_values = board->drop(); //board->drop() returns number of rows cleared
    int rows_cleared = drop_values.first;
    int points_gained = drop_values.second;
    score += pow((level+rows_cleared), 2) + points_gained;
    board->update_score(score);
    board->unblind();
    add_extra(rows_cleared); //template method
    return rows_cleared;
}

void Player::blind() {
    board = make_shared<Blind>(board);
    board->blind();
    ++num_effects;
}

void Player::heavy() {
    board = make_shared<Heavy>(board);
    ++num_effects;
}

void Player::force(char block_type) {
    board = make_shared<Force>(board, block_type);
    ++num_effects;
}

// Requires: effects have been placed
void Player::clear_effects() {
    board = board->get_parent();
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

void Player::update_level(int new_level) {
    board->update_level(new_level);
}

// Accessors:

void Player::add_window(shared_ptr<GraphicsDisplay> display) {
    board->add_window(display);
}

void Player::set_player_num(int n) {
    player_num = n;
}
  
int Player::get_level() const { return level; }
int Player::get_score() const { return score; }

vector<pair<int,int>> Player::get_next_coords() const {
    return next->get_coords(0);
}

char Player::get_next_block_type() const {
    return next->get_block_type();
}