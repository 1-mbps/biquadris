#ifndef _BASICBOARD_H_
#define _BASICBOARD_H_
#include "decorator.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

class BasicBoard: public Board {
    public:
        BasicBoard();
        ~BasicBoard();
};

#endif
