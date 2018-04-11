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
    /* Must have played WildCard so that it can be followed by another card... */
    return played && Card::operator^(following_card);
}

void WildCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: call chooseColor(), and add wildCard effect
}

void WildCard::init() {
    /* Shuffled wildCard becomes meta. */
    color = Color::meta;
    played = false;
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
