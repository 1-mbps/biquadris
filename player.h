#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "basicboard.h"

class Player {
    friend class Level0;
    shared_ptr<Board> board = nullptr;
    protected:
        int level = 0;
        int score = 0;
    public:
        virtual ~Player() = 0;
        Player& operator=(const Player &other);
        void add(shared_ptr<Block> b = nullptr);
        void drop(); //Drops block, returns number of rows cleared

        void print_line(int line);
        void blind();
        
        void rotate(bool clockwise);
        void left();
        void right();
        void up();
        void down();

        virtual shared_ptr<Block> block_selector() = 0;
        virtual void add_extra(int rows_cleared);
        virtual void move_modifier();

        // Accessors:
        int get_level();
        int get_score();
};

#endif
