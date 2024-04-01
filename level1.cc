#include "level1.h"

Level1::Level1() { board = make_shared<BasicBoard>(); }

Level1::~Level1() {}

// Text& Text::operator=(const Book &other) {
// 	Text &tref = dynamic_cast<Text&>(other); //cast other to a text
// 	if (this == &tref) return *this;
// 	Book::operator=(other);
// 	topic = tref.topic;
// 	return *this;
// }

// Text & Text::operator=(const Book &other){
// Text &tref = dynamic_cast<Text&>(other);
// if (this == &tref){ return *this);
// Book::operator=(other);
// topic = tref.topic; // cause book doesn’t have topic
// return *this;
// }


// Level1& Level1::operator=(Player &other) {
//     Level1 &lref = dynamic_cast<Level1&>(other); //cast other to a text
// 	if (this == &lref) return *this;
// 	Player::operator=(other);
// 	return *this;
// }

shared_ptr<Block> Level1::block_selector() {
    shared_ptr<Block> b(new Block('T'));
    return b;
}
