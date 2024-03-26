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
};

#endif
