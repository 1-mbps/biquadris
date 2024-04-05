#include "window.h"
#include <string>
#include <map>

using namespace std;

class GraphicsDisplay {
    Xwindow w;
    int x_coord;
    int y_coord;
    int start;
    map<char, int> color_map;
    static const int HEADBAR = 10;
    static const int WIDTH = 700;
    static const int BOARD_WIDTH = 330;
    static const int DIVIDER_WIDTH = 40;
    static const int HEIGHT = 640;
    static const int SIZE = BOARD_WIDTH/11;
    public:
        GraphicsDisplay();
        ~GraphicsDisplay();
        void notify(char (&grid)[18][11], int player_num);
};