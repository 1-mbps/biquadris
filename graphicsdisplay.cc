#include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay() {
    w.fillRectangle(BOARD_WIDTH, 0, DIVIDER_WIDTH, HEIGHT-HEADBAR, Xwindow::Black);
    char blocks[8] = {'I', 'J', 'L', 'O', 'S', 'Z', 'T', '*'};
    for (int i = 0; i < 8; ++i) {
        color_map[blocks[i]] = i+2;
    }
}

GraphicsDisplay::~GraphicsDisplay(){
    
}

void GraphicsDisplay::notify(char (&grid)[18][11], int player_num) {
    // cout << "notified!" << endl;
    int add_width = 0;
    if (player_num == 2) add_width = BOARD_WIDTH+DIVIDER_WIDTH;
    w.fillRectangle(add_width,HEADBAR,BOARD_WIDTH,HEIGHT-10,0);
    string msg;
    for (int i = 0; i < 21; ++i) {
        if (i == 0) {
            if (player_num == 1) {
                msg = "Level:          ";
            } else {
                msg = "Level:          ";
            }
            w.drawString(i*SIZE, HEADBAR, msg);
        } else if (i == 1) {
            if (player_num == 1) {
                msg = "Score:          ";
            } else {
                msg = "Score:          ";
            }
            w.drawString(i*SIZE, HEADBAR, msg);
        } else if(i == 2) {
            msg = "-------------------------------";
            w.drawString(i*SIZE, HEADBAR, msg);
        } else {
            for (int j = 0; j < 11; ++j) {
                if (grid[i-3][j] != ' ') {
                    // cout << "Colour: " << color_map[grid[i-3][j]] << endl;
                    w.fillRectangle(j*SIZE, (i*SIZE) + HEADBAR, SIZE, SIZE, color_map[grid[i-3][j]]);
                }
            }
        }
    }
}
