/*
 * ReverseCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "ReverseCard.h"
#include "Player.h"

ReverseCard::ReverseCard(Color color) : Card(color, POINT_REVERSECARD) {}

bool ReverseCard::operator^(const Card &following_card) const {
    // TODO: Add following reverse card policy
    return false;
}

void ReverseCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: Add reversing player effect
}

void ReverseCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << "r";
}
