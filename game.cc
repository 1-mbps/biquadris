#include "game.h"

Game::Game() {

    // When running on text mode, don't run these
    display = make_shared<GraphicsDisplay>();
    player1->add_window(display);
    player2->add_window(display);
    player1->set_player_num(1);
    player2->set_player_num(2);

    // player1->add();
    // player1->drop();
    // player2->add();
    // player2->drop();
    // print_players();

    char c;
    while (cin >> c) {
        if (c == 'r') player1->rotate(true);
        if (c == 'd') player1->drop();
        if (c == 'a') player1->add();
        if (c == 'L') player1->left();
        if (c == 'R') player1->right();
        if (c == 'b') player1->blind();
        if (c == 'f') player1->force('O');
        if (c == 'p') print_players();
        if (c == 'c') player1->clear_effects();
        if (c == 'q') break;
    }

    // print_players();
    // player1->add();
    // player1->right();
    // player1->right();
    // player1->right();
    // player1->right();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // print_players();
    // player1 = make_shared<Level1>(*player1);
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->rotate(true);
    // player1->rotate(true);
    // for (int i = 0; i < 15; ++i) player1->right();
    // print_players();
    // player1->drop();
    // print_players();
    // player1 = make_shared<Level4>(*player1);
    // player1->add();
    // player1->drop();
    // print_players();

    // //Add 5 blocks
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->add();
    // player1->drop();
    // player1->blind();

    // print_players();
    
    // player2 = make_shared<Level4>(*player2);
    // player2->add();
    // player2->drop();
    // player2 = make_shared<Level0>(*player2);
    // player2->add();
    // print_players();
    // On design document, write "fields are the same, so no need to overload copy assignment operator"
//     player2 = make_shared<Level4>(*player2);
//     player2->add();
//     player2->drop();
//     player2 = make_shared<Level0>(*player2);
//     player2->add();
//     player2->force('O');
//     player2->add();
//     player2->drop();
//     player2->add();
//     player2->drop();
//     player2->add();
//     player2->drop();
//     print_players();

}

Game::~Game() {
    levels.clear();
}

int num_digits(int n) {
    if (n < 10) return 1;
    return 1 + num_digits(n/10);
}

void Game::print_players() {
    string space = "        "; //8 spaces
    cout << "Level: " << player1->get_level() << space+"   " << "Level: " << player2->get_level() << endl;
    cout << "Score: " << player1->get_score() << space;
    
    for (int i = 0; i < 4-num_digits(player1->get_score()); ++i) cout << " ";

    cout << "Score: " << player2->get_score() << endl;
    
    cout << "-----------" << space << "-----------" << endl;
    for (int i = 0; i < 18; ++i) {
        player1->print_line(i);
        cout << space;
        player2->print_line(i);
        cout << endl;
    }
    cout << "-----------" << space << "-----------" << endl;
  
    vector<pair<int,int>> p1_next_coords = player1->get_next_coords();
    vector<pair<int,int>> p2_next_coords = player2->get_next_coords();
    char c1 = player1->get_next_block_type();
    char c2 = player2->get_next_block_type();
    char nexts[4][30];

    // cout << "got here!" << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 30; ++j) {
            nexts[i][j] = ' ';
        }
    }

    for (auto p : p1_next_coords) {
        nexts[p.first][p.second+3] = c1;
    }

    for (auto p : p2_next_coords) {
        nexts[p.first][p.second+22] = c2;
    }

    cout << "Next:" << "      "+space << "Next:" << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 30; ++j) {
            cout << nexts[i][j];
        }
        cout << endl;
    }
}
