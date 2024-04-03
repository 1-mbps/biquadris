#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "board.h"
#include <memory>

class Decorator: public Board {
    protected:
        shared_ptr<Board> component;
    public:
        Decorator(shared_ptr<Board> b);
        virtual ~Decorator();
        virtual pair<int,int> drop();
        virtual bool rotate(bool clockwise);
        virtual bool up();
        virtual bool down();
        virtual bool left();
        virtual bool right();
        virtual void print_line(int line);
        char get_point(int i, int j);
};

#endif
