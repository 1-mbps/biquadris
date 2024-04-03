#ifndef _GAME_H_
#define _GAME_H_
#include "player.h"
#include "levels.h"
#include <memory>

using namespace std;

class Game {
    shared_ptr<Player> player1 = make_shared<Level0>();
    shared_ptr<Player> player2 = make_shared<Level0>();
    vector<Player> levels;

    void print_players();

    public:
        Game();
        ~Game();
};

#endif
