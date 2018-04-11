/**
 *  @author: wpengae
 */
 
#include "DrawFourCard.h"
#include "Player.h"

DrawFourCard::DrawFourCard() : WildCard(POINT_DRAWFOURCARD) {}

bool DrawFourCard::operator^(const Card &following_card) const {
    // TODO: Add DrawFourCard following policy
}

void DrawFourCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    // TODO: call chooseColor(), and add DrawFourCard effect including next player challenging or not
}

void DrawFourCard::serialize(ostream &os) const {
    /* Different print result before and after played. */
    if (!played) {
        os << "+4";
    } else {
        os << "4" << (color == Color::red ? "R" :
                      color == Color::blue ? "B" :
                      color == Color::green ? "G" :
                      color == Color::yellow ? "Y" : "ERROR");
    }
}
