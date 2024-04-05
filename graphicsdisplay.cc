#include "graphicsdisplay.h"
#include <string>

using namespace std;

GraphicsDisplay::GraphicsDisplay() {
    w.fillRectangle(BOARD_WIDTH, 0, DIVIDER_WIDTH, HEIGHT, Xwindow::Black);
    w.drawLine(0,HEADBAR+BOARD_HEIGHT,WIDTH,HEADBAR+BOARD_HEIGHT+1);
    w.drawLine(0,HEADBAR,WIDTH,HEADBAR+1);
    print_header();
    w.drawString(NUMBER_GAP, LEVEL_Y, "0");
    w.drawString(NUMBER_GAP, SCORE_Y, "0");
    w.drawString(ADD_WIDTH+NUMBER_GAP, LEVEL_Y, "0");
    w.drawString(ADD_WIDTH+NUMBER_GAP, SCORE_Y, "0");
    w.drawString(5, HEADBAR+BOARD_HEIGHT+15, "Next:");
    w.drawString(ADD_WIDTH+5, HEADBAR+BOARD_HEIGHT+15, "Next:");
    char blocks[8] = {'I', 'J', 'L', 'O', 'S', 'Z', 'T', '*'};
    for (int i = 0; i < 8; ++i) {
        color_map[blocks[i]] = i+2;
    }
}

GraphicsDisplay::~GraphicsDisplay() {}

void GraphicsDisplay::print_header() {
    w.drawString(5, LEVEL_Y, "Level:");
    w.drawString(5, SCORE_Y, "Score:");
    w.drawString(ADD_WIDTH+5, LEVEL_Y, "Level:");
    w.drawString(ADD_WIDTH+5, SCORE_Y, "Score:");
}

void GraphicsDisplay::clear_header(int player_num) {
    int add_width = (player_num == 2)*ADD_WIDTH;
    w.fillRectangle(add_width,0,BOARD_WIDTH,HEADBAR,0);
}

void GraphicsDisplay::clear(int i, int j, int player_num) {
    int add_width = 0;
    if (player_num == 2) add_width = ADD_WIDTH;
    w.fillRectangle(add_width + (j*SIZE), (i*SIZE) + HEADBAR, SIZE, SIZE, 0);
}

void GraphicsDisplay::fill(int i, int j, char c, int player_num) {
    int add_width = 0;
    if (player_num == 2) add_width = BOARD_WIDTH+DIVIDER_WIDTH;
    int color = color_map[c];
    if (is_blind && 2 <= i && i <= 11 && 2 <= j && j <= 8) {
        color = 0;
    }
    w.fillRectangle(add_width + (j*SIZE), (i*SIZE) + HEADBAR, SIZE, SIZE, color);
}

void GraphicsDisplay::update_level(int l, int player_num) {
    int add_width = (player_num == 2)*ADD_WIDTH;
    clear_header(player_num);
    print_header();
    w.drawString(add_width+NUMBER_GAP, LEVEL_Y, to_string(l));
}

void GraphicsDisplay::update_score(int s, int player_num) {
    int add_width = (player_num == 2)*ADD_WIDTH;
    clear_header(player_num);
    print_header();
    w.drawString(add_width+NUMBER_GAP, SCORE_Y, to_string(s));
}

void GraphicsDisplay::blind() {
    is_blind = true;
}

void GraphicsDisplay::unblind() {
    is_blind = false;
}

void GraphicsDisplay::display_next(vector<pair<int,int>> coords, char c, int player_num) {
    int add_width = (player_num == 2)*ADD_WIDTH;
    for (auto p : coords) {
        cout << p.first << " " << p.second << endl;
        w.fillRectangle(20+(p.second*SIZE)+add_width, HEADBAR+BOARD_HEIGHT+40+((p.first+1)*SIZE), SIZE, SIZE, color_map[c]);
    }
}