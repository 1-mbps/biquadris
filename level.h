#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "block.h"
#include "memory"

using namespace std;

class Level {
    public:
        virtual ~Level() = 0;
        virtual shared_ptr<Block> block_selector() = 0;
        virtual void do_extra();
};

#endif
