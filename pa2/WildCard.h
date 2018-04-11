/*
 * WildCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw, wpengae
 */

#ifndef WILDCARD_H_
#define WILDCARD_H_

#include "Card.h"

class WildCard : public Card {
public:
    WildCard();
    
    virtual bool operator^(const Card &following_card) const override;
    
    virtual void castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) override;
    
    virtual void init() override;

protected:
    WildCard(int point);
    
    virtual void serialize(ostream &os) const override;
    
    bool played = false;
    
};

#endif /* WILDCARD_H_ */
