#include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay() {
    w.fillRectangle(330, 0, 40, 630, Xwindow::Black);
}

GraphicsDisplay::~GraphicsDisplay(){
    
}

void GraphicsDisplay::notify(char (&grid)[18][11]) {
    string msg;
    for (int i = 0; i < 21; ++i) {
        if (i == 0) {
            // if (player == 1) {
            //     msg = "Level:          ";
            // } else {
            //     msg = "Level:          ";
            // }
            // w.drawString(i*SIZE, HEADBAR, msg);
        } else if (i == 1) {
            // if (player == 1) {
            //     msg = "Score:          ";
            // } else {
            //     msg = "Score:          ";
            // }
            // w.drawString(i*SIZE, HEADBAR, msg);
        } else if(i == 2) {
            // msg = "-------------------------------";
            // w.drawString(i*SIZE, HEADBAR, msg);
        } else {
            for (int j = 0; j < 11; ++j) {
                if(grid[i-3][j] == 'I') {
                    w.fillRectangle(i*SIZE, j*SIZE+HEADBAR, SIZE, SIZE, 0);
                }
                if(grid[i-3][j] == 'J') {
                    w.fillRectangle(i*SIZE, j*SIZE+HEADBAR, SIZE, SIZE, 1);
                }   
                if(grid[i-3][j] == 'L') {
                    w.fillRectangle(i*SIZE, j*SIZE+HEADBAR, SIZE, SIZE, 2);
                }
                if(grid[i-3][j] == 'O') {
                    w.fillRectangle(i*SIZE, j*SIZE+HEADBAR, SIZE, SIZE, 3);
                }
                if(grid[i-3][j] == 'S') {
                    w.fillRectangle(i*SIZE, j*SIZE+HEADBAR, SIZE, SIZE, 4);
                }
                if(grid[i-3][j] == 'Z') {
                    w.fillRectangle(i*SIZE, j*SIZE+HEADBAR, SIZE, SIZE, 5);
                }
                if(grid[i-3][j] == 'T') {
                    w.fillRectangle(i*SIZE, j*SIZE+HEADBAR, SIZE, SIZE, 6);
                }
            }
        }
    }
}
