#include "window.h"
#include <string>
#include <map>
#include <vector>

using namespace std;

class GraphicsDisplay {
    int x_coord;
    int y_coord;
    int start;
    map<char, int> color_map;
    static const int HEADBAR = 40;
    static const int WIDTH = 700;
    static const int DIVIDER_WIDTH = 40;

    // DO NOT CHANGE

    static const int BOARD_WIDTH = (WIDTH-DIVIDER_WIDTH)/2;
    static const int ADD_WIDTH = BOARD_WIDTH + DIVIDER_WIDTH;
    static const int SIZE = BOARD_WIDTH/11;
    static const int BOARD_HEIGHT = SIZE*18;
    static const int HEIGHT = (2*HEADBAR) + BOARD_HEIGHT + (5*SIZE); //Window height
    
    // <-- -->
    
    static const int LEVEL_Y = 15;
    static const int SCORE_Y = LEVEL_Y + 15;
    static const int NUMBER_GAP = 45;
    bool is_blind = false;
    Xwindow w{WIDTH, HEIGHT};

    void print_header();
    void clear_header(int player_num);

    public:
        GraphicsDisplay();
        ~GraphicsDisplay();
        void clear(int i, int j, int player_num);
        void fill(int i, int j, char c, int player_num);
        void update_level(int l, int player_num);
        void update_score(int s, int player_num);
        void blind();
        void unblind();
        void display_next(vector<pair<int,int>> coords, char c, int player_num);
};