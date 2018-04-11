/*
 * NumberCard.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"
#include "ReverseCard.h"

NumberCard::NumberCard(int number, Color color) : Card(color, number) {}

bool NumberCard::operator^(const Card &following_card) const {
    if (typeid(following_card).name() == typeid(NumberCard).name()) {
        /* Followed by a number card: valid if same color or same point. */
        return Card::operator^(following_card) || following_card.getPoint() == getPoint();
//    } else if (typeid(following_card).name() == typeid(ReverseCard).name()) {
        /* Followed by a reverse card then only need to check its color. */
//        return Card::operator^(following_card);
    }
    // TODO: Add other cards checking validity
//    } else if (typeid(following_card).name() == typeid(SkipCard).name()) {
//    }
    /* Unknown type of card, should be error! */
    cerr << "ERROR: Unknown type of card!" << endl;
    return false;
}

void NumberCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: Adds implementation of effect
}

void NumberCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << getPoint();
}

