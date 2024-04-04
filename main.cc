#include "game.h"
#include <iostream>
#include <memory>
#include "window.h"

using namespace std;

int main() {
    // Game game{{Level1{}, Level2{}}};
    // Xwindow w;
    // w.fillRectangle(330, 0, 40, 630, Xwindow::Black);
    Game game;
    //tests
    /*w.drawString(10, 10, "Hello There Buddy");
    w.fillRectangle(0, 30, 30, 30, 5);
    w.fillRectangle(60, 90, 30, 30, 5);
    w.fillRectangle(150, 180, 30, 30, 5);
    */

   /*Game g;
   char grid[11][18] = {""};
   GraphicsDisplay graphics(g, grid);
   g.attach(&graphics);
    */
   //idek man
}

//This is purely for testing purposes - nowhere close to an actual harness
// int main() {

//     cout << "Board with block:" << endl << endl;
//     shared_ptr<Board> board = make_shared<BasicBoard>();
//     board->add('T');
//     board->print();
//     board->rotate(true);

//     cout << endl << "Board with block rotated clockwise" << endl << endl;
//     board->print();

//     board->rotate(false);
//     cout << endl << "Board with block rotated counterclockwise to original position and then shifted right" << endl << endl;
    
//     board->right();
//     board->right();
    
//     board->print();

//     board = make_shared<Heavy>(board);
//     board = make_shared<Blind>(board);

//     board->left();
//     board->print();

//     // block.rotate(false);
//     // block.rotate(false);
//     // block.rotate(true);

//     // block.print();

//     // pair<int, int> tl = block()
//     board.reset();

//     return 0;
// }
