#include "playermoney.h"

playerMoney::playerMoney()
{
    currentMoney = 0;
}

void playerMoney::increaseMoney(int value){
    currentMoney+=value;

}

void playerMoney::decreaseMoney(int value){
    currentMoney -= value;
}

void playerMoney::setMoney( int value){
    currentMoney = value;
}

int playerMoney::getCurrentMoney(){
    return currentMoney;
}


