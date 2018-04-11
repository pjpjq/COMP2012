/*
 * Card.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw, wpengae
 */

#include "Card.h"

bool Card::operator^(const Card &t) const {
    return t.color == color || t.color == Color::meta;
}

Card::Card(Color color, int point) : color(color), point(point) {}

