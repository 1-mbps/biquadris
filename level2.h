#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include "player.h"

class Level2: public Player {
    public:
        Level2();
        Level2(const Player &p);
        ~Level2();
        shared_ptr<Block> block_selector() override;
        void do_extra() override;
};

#endif
