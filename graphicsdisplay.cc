#include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(){
}

GraphicsDisplay::~GraphicsDisplay(){
    
}

void GraphicsDisplay::notify(char (&grid)[18][11]) {
    string msg;
    for (int i = 0; i < 21; ++i) {
        if (i == 0) {
            if (player == 1) {
                msg = "Level:          ";
            } else {
                msg = "Level:          ";
            }
            w.drawString(x_coord*SIZE, y_coord*SIZE+HEADBAR, msg);
        } else if (i == 1) {
            if (player == 1) {
                msg = "Score:          ";
            } else {
                msg = "Score:          ";
            }
            w.drawString(x_coord*SIZE, y_coord*SIZE+HEADBAR, msg);
        } else if(i == 2) {
            msg = "-------------------------------";
            w.drawString(x_coord*SIZE, y_coord*SIZE+HEADBAR, msg);
        } else {
            for (int j = 0; j < 11; ++j) {
                if(grid[i-3][j] == 'I') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 0);
                }
                if(grid[i-3][j] == 'J') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 1);
                }   
                if(grid[i-3][j] == 'L') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 2);
                }
                if(grid[i-3][j] == 'O') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 3);
                }
                if(grid[i-3][j] == 'S') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 4);
                }
                if(grid[i-3][j] == 'Z') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 5);
                }
                if(grid[i-3][j] == 'T') {
                    w.fillRectangle(x_coord*SIZE, y_coord*SIZE+HEADBAR, SIZE, SIZE, 6);
                }
            }
        }
    }
}
