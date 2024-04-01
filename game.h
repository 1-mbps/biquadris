#ifndef _GAME_H_
#define _GAME_H_
#include "player.h"
#include "level1.h"
#include <memory>

using namespace std;

class Game {
    shared_ptr<Player> player1 = make_shared<Level1>();
    shared_ptr<Player> player2 = make_shared<Level1>();
    vector<Player> levels;

    public:
        Game();
        ~Game();
};

#endif
