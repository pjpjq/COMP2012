/*
 * SkipCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "SkipCard.h"
#include "Player.h"

SkipCard::SkipCard(Color color) : Card(color, POINT_SKIPCARD) {}

void SkipCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: Add skip next player effect
}

void SkipCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << "s";
}

SkipCard::SkipCard(Color color, int point) : Card(color, point) {}
