#ifndef TOWNHALL_H
#define TOWNHALL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "health.h"


class Townhall: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    static qreal healthValue;

    Townhall( );
    //void upgrade();
    //void townhallAttacked();
    //bool getStatus();
    //int reduceHealth();
    bool remove;
    Health* townhallHealth;
    void UpgradeButton();
    QPair<int, int> GridPosition;


private:
    //bool destroyed;
};


#endif // TOWNHALL_H

