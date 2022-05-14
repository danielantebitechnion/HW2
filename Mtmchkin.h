#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);


    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    /*
     *D'tor , delete the m_cardsArray memory allocation
     */

    ~Mtmchkin();

private:
    //private funcion the Update m_gameStatus
    void updateGameStatus();

    //Variable from Card class that contain array of cards
    Card* m_cardsArray = NULL;

    //Variable that contain the game status
    GameStatus m_gameStatus;

    //Variable from class Player that contain the Player details
    Player m_player;

    //Variable that contain the index of the current card that should play
    int m_currentCard =0;

    //number of cards in game
    const int m_numOfCards;
};


#endif //EX2_GAME_H
