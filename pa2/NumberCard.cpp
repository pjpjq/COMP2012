/*
 * NumberCard.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"

NumberCard::NumberCard(int number, Color color) : Card(color, number) {}

bool NumberCard::operator^(const Card &following_card) const {
    /* Same color or same point! */
    return Card::operator^(following_card) || following_card.getPoint() == getPoint();
}

void NumberCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: Need implementation of effect???
    // No effect for a numberCard...
}

void NumberCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << getPoint();
}

