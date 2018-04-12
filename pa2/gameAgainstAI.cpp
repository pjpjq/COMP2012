/**
 * Test the UNO game by playing with some AI agents!
 *
 * @author wpengae
 */
#include <iostream>
#include "Player.h"
#include "NumberCard.h"
#include "SkipCard.h"
#include "ReverseCard.h"
#include "DrawTwoCard.h"
#include "DrawFourCard.h"
#include "WildCard.h"

using namespace std;

class Agent : public Player {
public:
    Agent(string s, Player *a = nullptr) : Player(s, a) {
        srand(time(nullptr));
    }
    
    virtual bool appealDrawFour() const {
        bool appeal = rand() % 2;
        printf("The next agent ");
        if (appeal) {
            printf("appealed!\n");
        } else {
            printf("didn't appeal...\n");
        }
        return appeal;
    }
    
    virtual Color chooseColor() const {
        
        int randomChoice = rand() % 4;
        return randomChoice == 0 ? Color::blue :
               randomChoice == 1 ? Color::green :
               randomChoice == 2 ? Color::red :
               Color::yellow;
    }
};

int main() {
    CardPile drawPile;
    CardPile discardPile;
    
    srand(time(nullptr));
    
    for (int i = 0; i < 8; ++i) {
        drawPile += new NumberCard(i, Color::red);
        drawPile += new NumberCard(i, Color::blue);
        drawPile += new NumberCard(i, Color::green);
        drawPile += new NumberCard(i, Color::yellow);
    }
    
    // draw a number card to the discard pile.
    drawPile.shuffle();
    Card *topCard = drawPile.removeTopCard();
    discardPile += topCard;
    
    drawPile += new ReverseCard(Color::red);
    drawPile += new ReverseCard(Color::blue);
    drawPile += new ReverseCard(Color::green);
    drawPile += new ReverseCard(Color::yellow);
    
    drawPile += new SkipCard(Color::red);
    drawPile += new SkipCard(Color::blue);
    drawPile += new SkipCard(Color::green);
    drawPile += new SkipCard(Color::yellow);
    
    drawPile += new DrawTwoCard(Color::red);
    drawPile += new DrawTwoCard(Color::blue);
    drawPile += new DrawTwoCard(Color::green);
    drawPile += new DrawTwoCard(Color::yellow);
    
    drawPile += new WildCard();
    drawPile += new WildCard();
    drawPile += new WildCard();
    drawPile += new WildCard();
    
    drawPile += new DrawFourCard();
    drawPile += new DrawFourCard();
    drawPile += new DrawFourCard();
    drawPile += new DrawFourCard();
    
    drawPile.shuffle();
    
    /* Sets up number of agents. */
    int numOfAgents;
    do {
        cout << "#agents you want to compete with? (enter 1-6)" << endl;
        cin >> numOfAgents;
    } while (numOfAgents < 1 || numOfAgents > 6);
    
    Player **players = new Player *[numOfAgents + 1];
    const string PLAYER_NAMES[7] = {"You", "Agent1", "Agent2", "Agent3", "Agent4", "Agent5", "Agent6"};
    
    /* Circular linked list. */
    players[0] = new Player(PLAYER_NAMES[0]);
    for (int i = 1; i < numOfAgents + 1; ++i) {
        players[i] = new Agent(PLAYER_NAMES[i], players[i - 1]);
    }
    
    /* Ready... go! Every player draw 5 cards first. */
    for (int i = 0; i < numOfAgents + 1; ++i) {
        players[i]->drawCard(drawPile, discardPile, 5);
    }
    
    /* Man, you play first! */
    Player *currentPlayer = players[0];
    Card *cardToPlay = nullptr;
    bool gameOver = false;
    
    while (!gameOver) {
        cout << "TopCard: " << *topCard << endl;
        cout << *currentPlayer << endl;
        if (currentPlayer == players[0]) { /* Man, it is your turn! */
            int input;
            int numOfInputFailures = 0;
            do {
                cout << "Type the index (start with 0) to play the card, or type -1 to draw one card:" << endl;
                cin >> input;
                if (input == -1) {
                    cout << "You drew one card..." << endl;
                    currentPlayer->drawCard(drawPile, discardPile, 1);
                    cardToPlay = nullptr;
                } else {
                    cardToPlay = currentPlayer->playCardAfter(topCard, input);
                    if (cardToPlay) {
                        cout << "You played: " << *cardToPlay << endl;
                    } else {
                        cout << "Invalid input, please try again" << endl;
                    }
                }
                ++numOfInputFailures;
            } while (input != -1 && !cardToPlay && numOfInputFailures < 50); /* preventing infinite loop! */
            /* Casts the effect of the card if played.
             * A NumberCard has no effect. Only function cards might have effects. */
            if (cardToPlay) {
                /* it is important that the effect is casted before it replaces the topCard .*/
                cardToPlay->castEffect(currentPlayer, drawPile, discardPile);
                topCard = cardToPlay;
                discardPile += topCard;
            }
        } else {  /* Oh, it's the agent's turn... */
            int agentIndex = 1;
            for (int i = 1; i < numOfAgents + 1; ++i) {
                if (players[i] == currentPlayer) {
                    agentIndex = i;
                }
            }
            for (int i = 0; i < 30; ++i) { /* Well, the agent is too lazy to check cards indexed >= 30... */
                cardToPlay = currentPlayer->playCardAfter(topCard, i);
                if (cardToPlay) {
                    printf("Agent %d played: ", agentIndex);
                    cout << *cardToPlay << endl;
                    cardToPlay->castEffect(currentPlayer, drawPile, discardPile);
                    topCard = cardToPlay;
                    discardPile += topCard;
                    break;
                }
            }
            if (!cardToPlay) {
                currentPlayer->drawCard(drawPile, discardPile, 1);
                printf("Agent %d drew one card...\n", agentIndex);
            }
        }
        
        currentPlayer = currentPlayer->getNextPlayer();
        
        /* Checks if the game is over. */
        cout << "Current hands of all players:" << endl << endl;
        for (int i = 0; i < numOfAgents + 1; ++i) {
            cout << *players[i] << endl;
            gameOver |= players[i]->win();
        }
        cout << "-----------------------------" << endl;
    }
    
    /* Prints the result. */
    cout << "==================================" << endl;
    cout << "GAME OVER!" << endl;
    if (players[0]->win()) {
        cout << "Congratulations, you win!" << endl;
    }
    for (int i = 0; i < numOfAgents + 1; ++i) {
        if (players[i]->win()) {
            cout << "Winner!\t\t";
        } else {
            cout << "Score: " << players[i]->getScore() << "\t";
        }
        cout << *players[i] << endl;
        
        delete players[i];
    }
    delete[] players;
    return 0;
}
