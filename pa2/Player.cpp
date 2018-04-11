/*
 * Player.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "Player.h"

ostream &operator<<(ostream &os, const Player &h) {
    os << h.name << ":";
    for (int i = 0; i < h.getSize(); i++) {
        os << *h.getCard(i) << " ";
    }
    return os;
}

Player::Player(string name, Player *previous) : name(name) {
    if (!previous) {
        nextPlayer = this;
    } else {
        nextPlayer = previous->getNextPlayer();
        /* Private is per class not per object!!! */
        previous->nextPlayer = this;
    }
}

void Player::drawCard(CardPile &drawPile, CardPile &discardPile, int number_of_cards) {
    
}

Card *Player::playCardAfter(const Card *topCard, int index) {
    return nullptr;
}

int Player::getScore() const {
    int total_score = 0;
    for (int i = 0; i < getSize(); ++i) {
        total_score += getCard(i)->getPoint();
    }
    return total_score;
}
