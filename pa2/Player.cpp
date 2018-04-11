/*
 * Player.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw, wpengae
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
    for (int i = 0; i < number_of_cards; ++i) {
        if (drawPile.getSize() == 0) {
            if (discardPile.getSize() <= 1) {
                /* Both piles cannot be drawn anymore then stop. */
                return;
            }
            /* Moves all cards below the top of discardPile to drawPile and shuffles. */
            for (int j = discardPile.getSize() - 2; j >= 0; --j) {
                drawPile += discardPile.removeCard(j);
            }
            drawPile.shuffle();
        }
        /* Player gets the top card of the drawPile. */
        (*this) += drawPile.removeTopCard();
    }
}

Card *Player::playCardAfter(const Card *topCard, int index) {
    if (!(*topCard ^ *getCard(index)) || index >= getSize()) {
        /* Invalid card */
        return nullptr;
    }
    return removeCard(index);
    /* Doesn't need to add the card to discardPile because it is not players' job. */
}

int Player::getScore() const {
    int total_score = 0;
    for (int i = 0; i < getSize(); ++i) {
        total_score += getCard(i)->getPoint();
    }
    return total_score;
}
