#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "level.h"
#include "basicboard.h"

class Player {
    int level = 0;
    int score = 0;
    shared_ptr<Board> board = make_shared<BasicBoard>();
    shared_ptr<Level> level_class;
    public:
        Player();
        ~Player();
        void add();
        void drop();

        void print();
        void blind();
        
        void left();
        void right();

        void set_level_class(shared_ptr<Level> lvl);
};

#endif
