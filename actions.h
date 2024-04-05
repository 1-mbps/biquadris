#ifndef __ACTIONS_H__
#define __ACTIONS_H__
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
        pair<int,int> drop() override;
        void print_line(int line) override;
};

class Heavy: public Decorator {
    public:
        Heavy(shared_ptr<Board> b);
        bool left() override;
        bool right() override;
};

class Force: public Decorator {
    char block_type;
    public:
        Force(shared_ptr<Board> b, char block_type);
        void add(shared_ptr<Block> b) override;
};

#endif
