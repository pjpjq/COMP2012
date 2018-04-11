/*
 * Card.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw, wpengae
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <iostream>

#include "enumAndConst.h"

using namespace std;

class CardPile;

class Player;

class Card {
    
    friend ostream &operator<<(ostream &os, const Card &c) {
        c.serialize(os);
        return os;
    }

public:
    Card(Color color, int point);
    
    // Return true if playing the card t after this card is valid. False if vice-versa.
    // e.g. "(a ^ b)" should return true if b can be played after a.
    // Legal or illegal is for drawFourCard instead, not considered here.
    virtual bool operator^(const Card &t) const;
    
    /**
     * Sequence of playing a card:
     *  1. Judging if playing the card is valid
     *  2. Removing the card from the player's hand
     *  3. Casting the effect of the card (castEffect() here)
     *  4. Adding the card to the discardPile and becoming the top-card
     */
    virtual void castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) = 0;
    
    virtual ~Card() = default;
    
    // return the point of the card
    int getPoint() const { return point; }
    
    // Does not do anything here for most of the card.
    // This will be called when     the deck is re-shuffled.
    // WildCard and DrawFourCard assigned with specific color should restore its color to Color::meta in this function.
    virtual void init() {}

protected:
    // Print the card
    virtual void serialize(ostream &os) const = 0;
    
    Color color;

private:
    const int point;
    
};

#endif /* CARD_H_ */
