#include "Mtmchkin.h"

#define MAX_LEVEL 10
int Mtmchkin::m_currentCard = 0;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards){
    this->m_player = Player(playerName);
    this->m_gameStatus = GameStatus::MidGame;
    this->m_numOfCards = numOfCards;
    this->m_cardsArray = new Card[numOfCards];
    for(int i=0;i<numOfCards;++i){
        this->m_cardsArray[i] = cardsArray[i];
    }
}
Mtmchkin::Mtmchkin(){
    m_cardsArray = NULL;
    m_gameStatus = GameStatus::MidGame;
    m_player = NULL;
    m_currentCard = -1;
    m_numOfCards =0;

}

Mtmchkin::~Mtmchkin(){
    delete[] m_cardsArray;
}

Mtmchkin::Mtmchkin(const Mtmchkin& mtm):
    m_cardsArray(new Card[m_numOfCards]){
        for(int i=0;i<m_numOfCards; ++i){
            m_cardsArray[i] = this->m_cardsArray[i];
        }
    }


Mtmchkin::Mtmchkin(const char *playerName){
    m_player = Player(playerName);
}

void Mtmchkin::playNextCard(){
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
    if(m_player.getLevel()>=MAX_LEVEL){
        m_gameStatus = GameStatus::Win;
    }
    else if(m_player.isKnockedOut()){
        m_gameStatus = GameStatus::Loss;
    }
}

bool Mtmchkin::isOver() const{
    if(getGameStatus() == GameStatus::Loss || getGameStatus()==GameStatus::Win){
        return true;
    }
    return false;
}

GameStatus Mtmchkin::getGameStatus() const{
    return this->m_gameStatus;
}
