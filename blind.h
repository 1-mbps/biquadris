#ifndef __BLIND_H__
#define __BLIND_H__
#include "board.h"
#include "decorator.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Blind: public Decorator {
    bool dropped = false;
    public:
        Blind(shared_ptr<Board> b);
        int drop() override;
        void print() override;
};

#endif
