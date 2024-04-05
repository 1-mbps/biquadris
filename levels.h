#ifndef __LEVELS_H__
#define __LEVELS_H__
#include "player.h"
#include <vector>

class Level0: public Player {
    vector<char> chars;
    size_t char_length = 0;
    size_t char_num = 0;
    public:
        Level0();
        Level0(const Player &p);
        ~Level0();
        shared_ptr<Block> block_selector() override;
};

class Level1: public Player {
    char selections[12] = {'S', 'Z', 'I', 'I', 'L', 'L', 'J', 'J', 'T', 'T', 'O', 'O'};
    public:
        Level1();
        Level1(const Player &p);
        ~Level1();
        shared_ptr<Block> block_selector() override;
};

class Level2: public Player {
    char selections[7] = {'I', 'L', 'J', 'O', 'T', 'Z', 'S'};
    public:
        Level2();
        Level2(const Player &p);
        ~Level2();
        shared_ptr<Block> block_selector() override;
};

class Level3: public Player {
    char selections[9] = {'S', 'S', 'Z', 'Z', 'I', 'L', 'J', 'O', 'T'};
    public:
        Level3();
        Level3(const Player &p);
        ~Level3();
        shared_ptr<Block> block_selector() override;
        void move_modifier() override;
};

class Level4: public Player {
    char selections[9] = {'S', 'S', 'Z', 'Z', 'I', 'L', 'J', 'O', 'T'};
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
