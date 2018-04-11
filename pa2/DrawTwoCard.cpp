/*
 * DrawTwoCard.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw, wpengae
 */

#include "DrawTwoCard.h"
#include "Player.h"

DrawTwoCard::DrawTwoCard(Color color) : SkipCard(color, POINT_DRAWTWOCARD) {}

void DrawTwoCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: Next player draw two cards from the drawPlie, skip, need shuffle if not enough card to draw
}

void DrawTwoCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << "+";
}
