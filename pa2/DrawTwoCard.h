/*
 * DrawTwoCard.h
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw, wpengae
 */

#ifndef DRAWTWOCARD_H_
#define DRAWTWOCARD_H_

#include "SkipCard.h"

class DrawTwoCard : public SkipCard {
public:
    DrawTwoCard(Color color);
    
    virtual void castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) override;

protected:
    virtual void serialize(ostream &os) const override;
};

#endif /* DRAWTWOCARD_H_ */
