#include "graphicsdisplay.h"
GraphicsDisplay::GraphicsDisplay(Game g, char grid[11][18] ){
}

GraphicsDisplay::~GraphicsDisplay(){
    
}

void GraphicsDisplay::notify(){
    for (int i = 0; i < 21; ++i) {
        string msg;
        if (i == 0) {
            if (player == 1) {
                msg = "Level:          " + g.p1_level();
            } else {
                msg = "Level:          " + g.p2_level();
            }
            w.drawString(x_coord*SIZE, y_coord*SIZE+HEADBAR, msg);
        } else if (i == 0) {
            if (player == 1) {
                msg = "Score:          " + g.p1_score();
            } else {
                msg = "Score:          " + g.p2_score();
            }
            w.drawString(x_coord*SIZE, y_coord*SIZE+HEADBAR, msg);
        } else if(i == 2) {
            msg = "-------------------------------";
            w.drawString(x_coord*SIZE, y_coord*SIZE+HEADBAR, msg);
        } else {
            for (int j = 0; j < 11; ++j) {
                if(grid[i][j] == 'I') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 0);
                }
                if(grid[i][j] == 'J') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 1);
                }   
                if(grid[i][j] == 'L') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 2);
                }
                if(grid[i][j] == 'O') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 3);
                }
                if(grid[i][j] == 'S') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 4);
                }
                if(grid[i][j] == 'Z') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 5);
                }
                if(grid[i][j] == 'T') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 6);
                }
            }
        }
    }
}
