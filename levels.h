#ifndef __LEVELS_H__
#define __LEVELS_H__
#include "player.h"

class Level0: public Player {
    public:
        Level0();
        ~Level0();
        shared_ptr<Block> block_selector() override;
};

class Level1: public Player {
    public:
        Level1();
        Level1(const Player &p);
        ~Level1();
        shared_ptr<Block> block_selector() override;
};

class Level2: public Player {
    public:
        Level2();
        Level2(const Player &p);
        ~Level2();
        shared_ptr<Block> block_selector() override;
};

class Level3: public Player {
    public:
        Level3();
        Level3(const Player &p);
        ~Level3();
        shared_ptr<Block> block_selector() override;
        void move_modifier() override;
};

class Level4: public Player {
    int moves_since_last_clear = 0;
    public:
        Level4();
        Level4(const Player &p);
        ~Level4();
        shared_ptr<Block> block_selector() override;
        void add_extra(int rows_cleared) override;
        void move_modifier() override;
};

#endif
