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
    Troop(int value);
    bool remove;
    void stop();
    qreal speed;
    Health* troopHealth;

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
