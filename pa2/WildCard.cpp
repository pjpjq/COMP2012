/*
 * WildCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#include "WildCard.h"
#include "Player.h"

WildCard::WildCard() : Card(Color::meta, POINT_WILDCARD) {}

bool WildCard::operator^(const Card &following_card) const {
    // TODO: Add wildCard following policy
    if (!played) {
        return false;
    }
}

void WildCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: call chooseColor(), and add wildCard effect
}

void WildCard::init() {
    /* Shuffled wildCard becomes meta. */
    color = Color::meta;
}

WildCard::WildCard(int point) : Card(Color::meta, point) {}

void WildCard::serialize(ostream &os) const {
    /* Different print result before and after played. */
    if (!played) {
        os << "WC";
    } else {
        os << (color == Color::red ? "R" :
               color == Color::blue ? "B" :
               color == Color::green ? "G" :
               color == Color::yellow ? "Y" : "ERROR") << "w";
    }
}
