/*
 * Card.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "Card.h"

bool Card::operator^(const Card &t) const {
    return t.color == color || t.color == Color::meta;
}

Card::Card(Color color, int mark) : color(color), point(mark) {}

