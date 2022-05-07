#include "Mtmchkin.h"


int Mtmchkin::m_currentCard = 0;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    this->m_player(playerName);
    this->m_gameStatus = GameStatus::MidGame;
    this->m_numOfCards = numOfCards;
    this->m_cardsArray = new Card[numOfCards];
    for(int i=0;i<numOfCards;++i){
        this->m_cardsArray[i] = cardsArray[i];
    }
}

void Mtmchkin::playNextCard(){
    Card curentCard = m_cardsArray[m_currentCard];
    curentCard.printInfo();
    curentCard.applyEncounter(m_player);
    m_player.printInfo(); 
    if(m_currentCard == m_numOfCards-1){//last card on pack
        m_currentCard =0;
    }
    else{
        m_currentCard++;
    }
}

bool Mtmchkin::isOver(){
    if(m_gameStatus==GameStatus::Loss ||m_gameStatus==GameStatus::Win){
        return true;
    }
    return false;
}

GameStatus Mtmchkin::getGameStatus() const{
    return this->m_gameStatus;
}
