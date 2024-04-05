#include "window.h"
#include <string>
#include <map>

using namespace std;

class GraphicsDisplay {
    int x_coord;
    int y_coord;
    int start;
    map<char, int> color_map;
    static const int HEADBAR = 10;
    static const int WIDTH = 700;
    static const int DIVIDER_WIDTH = 40;
    static const int BOARD_WIDTH = (WIDTH-DIVIDER_WIDTH)/2;
    static const int SIZE = BOARD_WIDTH/11;
    static const int BOARD_HEIGHT = SIZE*18;
    static const int HEIGHT = (2*HEADBAR) + BOARD_HEIGHT + (5*SIZE);
    Xwindow w{WIDTH, HEIGHT};
    public:
        GraphicsDisplay();
        ~GraphicsDisplay();
        void clear(int i, int j, int player_num);
        void fill(int i, int j, char c, int player_num);
};