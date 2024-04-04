#include "game.h"
#include "levels.h"

Game::Game() {
    // player1->add();
    // player1->right();
    // player1->right();
    // player1->rotate(true);
    // player1->drop();
    // player1->add();
    // player1->drop();
    // print_players();
    // player1 = make_shared<Level1>(*player1);
    // player1->add();
    // print_players();
    // player1->drop();
    // print_players();
    // player1->blind();
    // print_players();
    // player1->right();
    // player1->right();
    // player1->drop();
    // print_players();

    player1->add();
    player1->drop();
    player2->add();
    player2->drop();
    print_players();
    player1->add();
    player1->right();
    player1->right();
    player1->right();
    player1->right();
    player1->drop();
    player1->add();
    player1->drop();
    print_players();
    player1 = make_shared<Level1>(*player1);
    player1->add();
    player1->drop();
    player1->add();
    player1->rotate(true);
    player1->rotate(true);
    for (int i = 0; i < 15; ++i) player1->right();
    print_players();
    player1->drop();
    print_players();
    player1 = make_shared<Level4>(*player1);
    player1->add();
    player1->drop();
    print_players();

    //Add 5 blocks
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->add();
    player1->drop();
    player1->blind();

    print_players();
    
    player2 = make_shared<Level4>(*player2);
    player2->add();
    player2->drop();
    player2 = make_shared<Level0>(*player2);
    player2->add();
    print_players();

}

// need to add notifyObservers after each action in the while loop

Game::~Game() {
    levels.clear();
}

int num_digits(int n) {
    if (n < 10) return 1;
    return 1 + num_digits(n/10);
}

void Game::print_players() {
    string space = "        ";
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
    notifyObservers();
}

int Game::p1_level() {
    return player1->get_level();
}

int Game::p2_level() {
    return player2->get_level();
}

int Game::p1_score() {
    return player1->get_score();
}

int Game::p2_score() {
    return player2->get_score();
}

void Game::attach(Observer *o) {
    observers.emplace_back();
}

void Game::notifyObservers() {
    for (auto ob : observers) ob->notify();
}
