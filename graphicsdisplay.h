#include "window.h"
#include <string>

class GraphicsDisplay {
    Xwindow w;
    int x_coord;
    int y_coord;
    int start;
    int player;
    // Game g;
    // char grid[18][11];
    static const int HEADBAR = 10;
    static const int SIZE = 30;
    public:
        GraphicsDisplay();
        ~GraphicsDisplay();
        void notify(char (&grid)[18][11]);
};