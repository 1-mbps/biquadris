#ifndef _BOARD_H_
#define _BOARD_H_
#include "block.h"
#include "observer.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

// This is an abstract base class. As such, it has no constructor.
// To instantiate a board, use the BasicBoard class.
class Board {
    protected:
        const int r = 18; //Number of rows
        const int c = 11; //Number of columns
        char grid[18][11];
        int num_blocks = 0;
        vector<shared_ptr<Block>> blocks;
        vector<Observer*> observers;

        //Called by one of the rotation/translation functions whenever a block is updated.
        bool update_grid(int inc_rotation_state, int inc_r, int inc_c);

        //Checks if a coordinate (i,j) is valid.
        bool is_valid(int i, int j);

        //Checks if a coordinate (i,j) is within the bounds of the grid.
        bool is_within_bounds(int i, int j);

        // Returns how many points a user would get after clearing a row.
        int clear_row(int i);

        //Updates coordinates of all blocks on grid.
        //Called in drop function whenever a row is cleared.
        void recalibrate_grid(int rows_cleared);

        //add graphics display and make a class for it

    public:
        //Board is an abstract base class, so it must have at least one pure virtual method
        virtual ~Board() = 0;

        //Add a block to the grid.
        virtual void add(shared_ptr<Block> b);
        //In force class, override this to use block other player selected

        virtual pair<int,int> drop();
        //In blind class, override this to remove question marks

        //Rotate the block currently being edited.
        virtual bool rotate(bool clockwise);

        virtual bool up();
        virtual bool down();
        virtual bool left();
        virtual bool right();

        virtual char get_point(int i, int j);
        bool is_full(int i);
        
        //In blind class, this is overridden to print question marks if not dropped yet
        virtual void print_line(int line);
        
        //Observers for Graphics Display
        
        void attach(Observer *o);
        void notifyObservers(); 
};

#endif
