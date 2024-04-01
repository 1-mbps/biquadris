#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "player.h"

class Level1: public Player {
    public:
        Level1();
        ~Level1();
        shared_ptr<Block> block_selector() override;
};

#endif
