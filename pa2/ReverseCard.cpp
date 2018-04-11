/*
 * ReverseCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw, wpengae
 */

#include "ReverseCard.h"
#include "Player.h"
#include <typeinfo>

ReverseCard::ReverseCard(Color color) : Card(color, POINT_REVERSECARD) {}

bool ReverseCard::operator^(const Card &following_card) const {
    return Card::operator^(following_card) || typeid(following_card).name() == typeid(*this).name();
}

void ReverseCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    /*
     * Reversing all players' order, i.e., reversing the circular linked list
     * starting from the current player while keeping the current player unchanged.
     */
    if (!currentPlayer || !currentPlayer->getNextPlayer()) {
        /* 0 or 1 players, no need to reverse. */
        return;
    }
    /* 2 or more players */
    Player *cur = currentPlayer;
    /* currentPlayer is not actually current node (it's unchanged!)! cur is! */
    Player *nextToReverse = currentPlayer->getNextPlayer();
    while (nextToReverse != currentPlayer) {  /* Loops until the tail. */
        Player *toReverse = nextToReverse;
        nextToReverse = nextToReverse->getNextPlayer();
        toReverse->nextPlayer = cur;  /* Reverses. */
        cur = toReverse; /* Iterates cur. */
    }
    /* Tail (cur now) becomes the next player. */
    currentPlayer->nextPlayer = cur;
}

void ReverseCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << "r";
}
