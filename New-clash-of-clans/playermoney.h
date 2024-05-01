#ifndef PLAYERMONEY_H
#define PLAYERMONEY_H

class playerMoney
{
    int currentMoney;
public:

    playerMoney();
    void increaseMoney(int value);
    void decreaseMoney(int value);
    void setMoney(int value);
    int getCurrentMoney();

};

#endif // PLAYERMONEY_H
