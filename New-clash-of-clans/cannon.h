#ifndef CANNON_H
#define CANNON_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "health.h"
#include "bullet.h"

class Cannon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Cannon();
    void Upgrade(); //to upgrade cannon
    //void cannonAttacked(); //for handling collision with enemy
    //void setBulletDirection(int x, int y);
    //void shootBullet();
    //int reduceHealth();
    bool remove;
    void setImage(QPixmap image);
private:
    Health* cannonHealth;
    Bullet* bullet;
    qreal bulletDirectionX;
    qreal bulletDirectionY;
    //bool bulletMoving;
    //bool bulletFired;
    //QTimer *bulletTimer;
};

#endif // CANNON_H

