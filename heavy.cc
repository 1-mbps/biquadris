#include "heavy.h"

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
