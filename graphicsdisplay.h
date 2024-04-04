#include "observer.h"
#include "window.h"
#include "board.h"
#include "game.h"

class GraphicsDisplay: public Observer {
    Xwindow w;
    int x_coord;
    int y_coord;
    int start;
    int player;
    Game g;
    char grid[11][18];
    static const int HEADBAR = 10;
    static const int SIZE = 30;
    public:
        GraphicsDisplay(Game game, char grid[11][18]);
        ~GraphicsDisplay();
        void notify();
};