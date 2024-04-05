#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "basicboard.h"

class Player {
    friend class Level0;
    shared_ptr<Board> board = nullptr;
    int num_effects = 0;
    protected:
        int player_num;
        int level = 0;
        int score = 0;
        shared_ptr<Block> next = nullptr;
    public:
        virtual ~Player() = 0;
        Player& operator=(const Player &other);
        void add(shared_ptr<Block> b = nullptr);
        int drop(); //Drops block, returns number of rows cleared

        void print_line(int line);
        
        void rotate(bool clockwise);
        void left();
        void right();
        void up();
        void down();

        void blind();
        void heavy();
        void force(char block_type);
        void clear_effects();

        virtual shared_ptr<Block> block_selector() = 0;
        virtual void add_extra(int rows_cleared);
        virtual void move_modifier();

        void update_level(int new_level);

        void replace_block(char c);

        // Accessors:

        int get_level() const;
        int get_score() const;
  
        vector<pair<int,int>> get_next_coords() const;
        char get_next_block_type() const;
  
        void set_player_num(int n);
        void add_window(shared_ptr<GraphicsDisplay> display);
};

#endif
