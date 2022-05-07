#include "Card.h"
#include "utilities.h"

Card::Card(CardType type, const CardStats& stats){
    this->m_effect = type;
    this->m_stats = stats;
}

void Card::applyEncounter(Player& player) const{
    switch(m_effect){
        case CardType::Heal:
        case CardType::Buff:
            if(player.pay(m_stats.cost)){//enough money
                if(m_effect== CardType::Heal){//Heal card
                    player.heal(m_stats.heal);
                }
                else{//Buff card
                    player.buff(m_stats.buff);
                }
            }
            break;
        case CardType::Treasure:
            player.addCoins(m_stats.loot);     
            break;
        case CardType::Battle:
           if(player.getAttackStrenth() >= m_stats.force){//the player won the battle 
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
            }
            else{//player lost
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
            }
            break;  
    } 
}

void Card::printInfo() const{
    switch(m_effect){
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);   
            break;
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;  
    } 
}
