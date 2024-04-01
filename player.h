#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "basicboard.h"

class Player {
    protected:
        int level = 0;
        int score = 0;
        shared_ptr<Board> board = nullptr;
    public:
        virtual ~Player() = 0;
        Player& operator=(const Player &other);
        void add();
        void drop();

        void print();
        void blind();
        
        void rotate(bool clockwise);
        void left();
        void right();

        virtual shared_ptr<Block> block_selector() = 0;
        virtual void do_extra();

};

#endif
