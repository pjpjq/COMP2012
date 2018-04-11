/*
 * NumberCard.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw, wpengae
 */

#ifndef NUMBERCARD_H_
#define NUMBERCARD_H_

#include "Card.h"

class NumberCard : public Card {
public:
    NumberCard(int number, Color color);
    
    virtual bool operator^(const Card &following_card) const override;
    
    virtual void castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) override;

protected:
    virtual void serialize(ostream &os) const override;
    
};

#endif /* NUMBERCARD_H_ */
