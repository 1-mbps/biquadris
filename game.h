#ifndef _GAME_H_
#define _GAME_H_
#include "player.h"
#include "level.h"
#include <memory>

using namespace std;

class Game {
    Player player1;
    Player player2;
    vector<shared_ptr<Level>> levels;

    public:
        Game(vector<shared_ptr<Level>> levels);
        ~Game();
};

#endif
