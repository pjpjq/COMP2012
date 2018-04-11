/**
 *  @author: wpengae
 */

#include "DrawFourCard.h"
#include "Player.h"
#include <typeinfo>

void DrawFourCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    if (!currentPlayer || !currentPlayer->getNextPlayer()) {
        return;
    }
    /* Current player chooses color first, then asks if next player'd appeal. */
    color = currentPlayer->chooseColor();
    if (currentPlayer->getNextPlayer()->appealDrawFour()) {
        bool legal = true;
        for (int i = 0; i < currentPlayer->getSize(); ++i) {
            if (typeid(currentPlayer->getCard(i)).name() != typeid(DrawFourCard).name()) {
                /* Has another card to play! */
                legal = false;
                break;
            }
        }
        if (legal) { /* Bad appeal... */
            currentPlayer->getNextPlayer()->drawCard(drawPile, discardPile, 6);
            currentPlayer = currentPlayer->getNextPlayer();
        } else { /* Successful appeal! */
            currentPlayer->drawCard(drawPile, discardPile, 4);
        }
    } else { /* Doesn't want to appeal... */
        currentPlayer->getNextPlayer()->drawCard(drawPile, discardPile, 4);
        currentPlayer = currentPlayer->getNextPlayer();
    }
}

void DrawFourCard::serialize(ostream &os) const {
    /* Different print result before and after played. */
    if (color == Color::meta) {
        os << "+4";
    } else {
        os << "4" << (color == Color::red ? "R" :
                      color == Color::blue ? "B" :
                      color == Color::green ? "G" :
                      color == Color::yellow ? "Y" : "ERROR");
    }
}
