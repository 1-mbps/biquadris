#ifndef __HEAVY_H__
#define __HEAVY_H__
#include "board.h"
#include "decorator.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Heavy: public Decorator {
    public:
        Heavy(shared_ptr<Board> b);
        bool left() override;
        bool right() override;
};

#endif
