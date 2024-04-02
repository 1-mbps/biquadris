#include "blind.h"

Blind::Blind(shared_ptr<Board> b): Decorator{b} {}

int Blind::drop() {
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
