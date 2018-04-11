/*
 * WildCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw, wpengae
 */

#include "WildCard.h"
#include "Player.h"

WildCard::WildCard() : Card(Color::meta, POINT_WILDCARD) {}

void WildCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    color = currentPlayer->chooseColor();
}

void WildCard::init() {
    /* Shuffled wildCard becomes meta. */
    color = Color::meta;
}

void WildCard::serialize(ostream &os) const {
    /* Different print result before and after played. */
    if (color == Color::meta) {
        os << "WC";
    } else {
        os << (color == Color::red ? "R" :
               color == Color::blue ? "B" :
               color == Color::green ? "G" :
               color == Color::yellow ? "Y" : "ERROR") << "w";
    }
}
