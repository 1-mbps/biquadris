#include "decorator.h"
#include <memory>

Decorator::Decorator(shared_ptr<Board> b): component{b} {}

Decorator::~Decorator() {
    component.reset(); //use reset() instead of delete for smart pointers
}