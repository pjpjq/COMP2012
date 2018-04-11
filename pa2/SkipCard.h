/*
 * SkipCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw, wpengae
 */

#ifndef SKIPCARD_H_
#define SKIPCARD_H_

#include "Card.h"
#include "Player.h"

class SkipCard : public Card {
public:
    SkipCard(Color color);
    
    virtual bool operator^(const Card &following_card) const override;
    
    virtual void castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) override;

protected:
    virtual void serialize(ostream &os) const override;
};

#endif /* SKIPCARD_H_ */
