#include "actions.h"

using namespace std;

// <----- BLIND ----->

Blind::Blind(shared_ptr<Board> b): Decorator{b} {}

pair<int,int> Blind::drop() {
    dropped = true;
    return component->drop();
}

void Blind::print_line(int line) {
    if (dropped == true) {
        component->print_line(line);
    } else {
        bool on_line = (2 <= line && line <= 11);
        for (int j = 0; j < 11; ++j) {
            if (on_line && (2 <= j && j <= 8)) {
                cout << '?';
            } else {
                cout << component->get_point(line,j);
            }
        }
    }
}

// <-----  ----->


// <----- HEAVY ----->

Heavy::Heavy(shared_ptr<Board> b): Decorator{b} {}

bool Heavy::left() {
    if (component->left()) {
        if (component->down()) {
            if (component->down()) {
                // If no space to go down 2 rows, drop (as per instructions)
                return true;
            } else {
                component->drop();
                return true;
            }
        }
    }
    return false;
}

bool Heavy::right() {
    if (component->right()) {
        if (component->down()) {
            if (component->down()) {
                // If no space to go down 2 rows, drop (as per instructions)
                return true;
            } else {
                component->drop();
                return true;
            }
        }
    }
    return false;
}

// <-----  ----->



// <----- FORCE ----->

Force::Force(shared_ptr<Board> b, char block_type): Decorator{b}, block_type{block_type} {}

void Force::add(shared_ptr<Block> b) {
    shared_ptr<Block> forced_block = make_shared<Block>(block_type, component->get_level());
    component->add(forced_block);
}

// <-----  ----->
