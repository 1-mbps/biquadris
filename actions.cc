#include "actions.h"

using namespace std;

// <----- BLIND ----->

Blind::Blind(shared_ptr<Board> b): Decorator{b} {}

pair<int,int> Blind::drop() {
    dropped = true;
    return component->drop();
}

void Blind::print() {
    if (dropped == true) {
        component->print();
    } else {
        cout << "-----------" << endl;
        for (int i = 0; i < 18; ++i) {
            for (int j = 0; j < 11; ++j) {
                if ((2 <= i && i <= 11) && (2 <= j && j <= 8)) {
                    cout << '?';
                } else {
                    cout << component->get_point(i,j);
                }
            }
            cout << endl;
        }
        cout << "-----------" << endl;
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

Force::Force(shared_ptr<Board> b): Decorator{b} {}

// <-----  ----->
