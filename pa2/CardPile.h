/*
 * CardPile.h
 *
 *  Created on: Jan 30, 2018
 *      Author: kevinw, wpengae
 */

#ifndef CARDPILE_H_
#define CARDPILE_H_

#include "Card.h"

class CardPile {
public:
    /* Adds a card to the top of the pile. Do nothing if param is nullptr. */
    CardPile &operator+=(Card *newCard);
    
    int getSize() const { return size; }
    
    /* Returns the removed card card[i]. */
    Card *removeCard(int index);
    
    Card *removeTopCard() { return removeCard(size - 1); }
    
    const Card *getCard(int index) const {
        if (index < 0 || index >= size) {
            return nullptr;
        }
        return cards[index];
    }
    
    const Card *getTopCard() const { return getCard(size - 1); }
    
    virtual ~CardPile();
    
    /**
     * Need to be called if drawPile is empty.
     * Doesn't contain moving card between piles, so
     * should be called after putting all cards below the top of discardPile
     * to the drawPile.
     */
    void shuffle();


private:
    /* # of cards in the pile. */
    int size = 0;
    
    Card **cards = nullptr;
};

#endif /* CARDPILE_H_ */
