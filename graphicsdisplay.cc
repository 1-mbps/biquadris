#include "graphicsdisplay.h"
#include <string>

using namespace std;

GraphicsDisplay::GraphicsDisplay() {
    w.fillRectangle(BOARD_WIDTH, 0, DIVIDER_WIDTH, HEIGHT, Xwindow::Black);
    w.drawLine(0,HEADBAR+BOARD_HEIGHT,WIDTH,HEADBAR+BOARD_HEIGHT+1);
    w.drawLine(0,HEADBAR,WIDTH,HEADBAR+1);
    w.drawString(5, LEVEL_Y, "Level:");
    w.drawString(5, SCORE_Y, "Score:");
    w.drawString(ADD_WIDTH+5, LEVEL_Y, "Level:");
    w.drawString(ADD_WIDTH+5, SCORE_Y, "Score:");
    char blocks[8] = {'I', 'J', 'L', 'O', 'S', 'Z', 'T', '*'};
    for (int i = 0; i < 8; ++i) {
        color_map[blocks[i]] = i+2;
    }
}

GraphicsDisplay::~GraphicsDisplay() {
    
}

void GraphicsDisplay::clear(int i, int j, int player_num) {
    int add_width = 0;
    if (player_num == 2) add_width = ADD_WIDTH;
    w.fillRectangle(add_width + (j*SIZE), (i*SIZE) + HEADBAR, SIZE, SIZE, 0);
}

void GraphicsDisplay::fill(int i, int j, char c, int player_num) {
    int add_width = 0;
    if (player_num == 2) add_width = BOARD_WIDTH+DIVIDER_WIDTH;
    w.fillRectangle(add_width + (j*SIZE), (i*SIZE) + HEADBAR, SIZE, SIZE, color_map[c]);
}

void GraphicsDisplay::update_level(int l) {

}

void GraphicsDisplay::update_score(int s) {
    w.drawString(5, SCORE_Y, to_string(s));
}