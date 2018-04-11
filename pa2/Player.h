/*
 * Player.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "NumberCard.h"
#include "ReverseCard.h"
#include "DrawFourCard.h"
#include "CardPile.h"
#include <iostream>
#include <string>

using namespace std;

/* Players should form a circular linked list. */
class Player : private CardPile {
    
    friend void ReverseCard::castEffect(Player *&, ::CardPile &, ::CardPile &);
    
    friend void DrawFourCard::castEffect(Player *&, ::CardPile &, ::CardPile &);
    
    /* Print player's hand. */
    friend ostream &operator<<(ostream &os, const Player &h);

public:
    Player(string name, Player *previous = nullptr);
    
    // It adds number_of_cards cards from the drawPile to Player's cards.
    // As mentioned above, in case there is not enough card in the drawPile,
    // we need to put back card from discardPile to drawPile and shuffle.
    // If the sum of discardPile and drawPile are still not enough,
    // this function should draw all possible cards for the player.
    //
    // For example, if the drawPile has 1 card, discardPile has 3 cards.
    // Four cards need to be drawn.
    // The player will first draw the card in the drawPile.
    // Then 2 card from the discardPile.
    // (excluding the top card of the discardPile) are placed back to the drawPile.
    // Shuffle the drawPile.
    // The player draw the remaining two card from the drawPile.
    void drawCard(CardPile &drawPile, CardPile &discardPile, int number_of_cards);
    
    // The player try to play the index-th card from his Card array (cards) after the topCard.
    // The function shall return nullptr without doing anything if either:
    //     1) The play is invalid; or
    //	   2) The index is out of bound (no such card).
    // Otherwise, the card being played is removed from the Player's hand and
    // the function returns the address of the card.
    // Remember to change both variable: cards and size.
    // No need to care about printing UNO in this PA...
    Card *playCardAfter(const Card *topCard, int index);
    
    
    // When a DrawFourCard is played, the next player (who need to draw four) can appeal
    // (ask to review the player's hand).
    //
    // If the current player (the player being reviewed) does have a card to play, we say
    // this play is illegal. In this case,
    //  1) the next player would NOT need to draw four cards, and
    //  2) the next player would NOT need to skip his turn, and
    //  3) the current player need to draw four cards.
    //
    // If the play is legal (the current player has no other playable card in his hand
    // other than DrawFourCard),
    //  1) the next player will need to draw 6 cards,
    //  2) the next player will skip his turn just like what it should be.
    //
    // Note: **Regardless legal or not**, the current player choose a color of his wish.
    //
    // When an appeal is made, this function appealDrawFour() has to be called as
    // nextPlayer->appealDrawFour(), not currentPlayer->appealDrawFour().
    //
    // When grading, this inline function will be replaced by some other code
    // to make sure you really call this function instead of coping code of the function.
    virtual bool appealDrawFour() const {
        char input;
        do {
            cout << name;
            cout << ": Do you want to appeal and review your previous's player hand? (Y/N)" << endl;
            cin >> input;
            if (input == 'Y') { return true; }
            if (input == 'N') { return false; }
        } while (1);
    }
    
    // For WildCard and DrawFourCard, player should pick their color after playing the card
    // (even if DrawFourCard is not played legally).
    // You should call this function whenever asking a user to select a color.
    // The player can only choose among Red, Yellow, Blue, and Green (meta is not allowed).
    virtual Color chooseColor() const {
        do {
            char input;
            cout << name;
            cout << ": After playing a function card you need to choose a color: (R, B, G, Y)." << endl;
            cin >> input;
            switch (input) {
                case 'R' :
                    return Color::red;
                case 'Y' :
                    return Color::yellow;
                case 'B' :
                    return Color::blue;
                case 'G' :
                    return Color::green;
            }
        } while (1);
    }
    
    Player *getNextPlayer() const { return nextPlayer; };
    
    /* See if the player wins or not. */
    bool win() const { return getSize() == 0; }
    
    virtual ~Player() {
        cout << "destructor of " << name << endl;
    }
    
    int getScore() const;

private:
    Player *nextPlayer;
    string name;
    
};


#endif /* PLAYER_H_ */
