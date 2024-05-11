#ifndef TROOP_H
#define TROOP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include "health.h"

class Troop : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Troop(qreal health, qreal power);
    bool remove;
    void stop();
    qreal speed;
    Health* troopHealth;
    void knockBack(qreal X, qreal Y);
    qreal troopPower;
    QPair<int, int> currGridPosition;
    QVector<QPair<int, int>> Path;
    bool moving = false;

public slots:
    void dance();

private:
    QTimer* m_timer;
    QTimer* danceTimer;
    QTimer* dTimer;
    bool dancing = false;

private slots:
    void danceUtil();

};

#endif // TROOP_H
