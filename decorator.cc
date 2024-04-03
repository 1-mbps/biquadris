#include "decorator.h"
#include <memory>

Decorator::Decorator(shared_ptr<Board> b): component{b} {}

Decorator::~Decorator() {
    component.reset(); //use reset() instead of delete for smart pointers
}

pair<int,int> Decorator::drop() {
    return component->drop();
}

bool Decorator::rotate(bool clockwise) {
    return component->rotate(clockwise);
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
