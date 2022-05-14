#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
m_player(Player(playerName)),m_gameStatus(GameStatus::MidGame),m_numOfCards(numOfCards)
,m_cardsArray(new Card[numOfCards]){
    for(int i=0; i<numOfCards; ++i){
        m_cardsArray[i] = cardsArray[i];
    }
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}

void Mtmchkin::updateGameStatus()
{
    if(m_player.getLevel()>=MAX_LEVEL){ //Player Won
        m_gameStatus = GameStatus::Win;
    }
    else if(m_player.isKnockedOut()){ //Player lost
        m_gameStatus = GameStatus::Loss;
    }
}

void Mtmchkin::playNextCard()
{
    if(m_gameStatus==GameStatus::MidGame){
        Card curentCard = m_cardsArray[m_currentCard];
        curentCard.printInfo();
        curentCard.applyEncounter(m_player);
        m_player.printInfo(); 

        if(m_currentCard >= m_numOfCards-1){//last card on pack
            m_currentCard =0;
        }
        else{
            ++m_currentCard;
        }
        updateGameStatus();
    }
}

bool Mtmchkin::isOver() const
{
    if(getGameStatus() == GameStatus::Loss || getGameStatus()==GameStatus::Win){
        return true;
    }
    //else - MidGame
    return false;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}

