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
    shared_ptr<GraphicsDisplay> display = nullptr;

    void print_players();

    public:
        Game();
        ~Game();

        //Accessors for Graphics Display
        int p1_level();
        int p2_level();
        int p1_score();
        int p2_score();
        
        
        //Observers for Graphics Display
        // void attach(Observer *o);
        // void notifyObservers(); 
};

#endif
