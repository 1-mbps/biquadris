#include "decorator.h"
#include <memory>

Decorator::Decorator(shared_ptr<Board> b): component{b} {}

Decorator::~Decorator() {
    component.reset(); //use reset() instead of delete for smart pointers
}

pair<int,int> Decorator::drop() {
    return component->drop();
}

shared_ptr<Board> Decorator::get_parent() {
    if (component->is_board()) return component;
    return component->get_parent();
}

bool Decorator::is_board() const {
    return false;
}

bool Decorator::rotate(bool clockwise) {
    return component->rotate(clockwise);
}

void Decorator::add(shared_ptr<Block> b) {
    component->add(b);
}

bool Decorator::up() {
    return component->up();
}

bool Decorator::down() {
    return component->down();
}

bool Decorator::left() {
    return component->left();
}

bool Decorator::right() {
    return component->right();
}

void Decorator::print_line(int line) {
    return component->print_line(line);
}

char Decorator::get_point(int i, int j) {
    return component->get_point(i,j);
}

void Decorator::blind() {
    component->blind();
}

void Decorator::unblind() {
    component->unblind();
}
