#ifndef BOOSTER_H
#define BOOSTER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "cannon.h"


class Booster : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    QTimer* timer;
    Cannon* tempCannon;
    qreal originalPower;

private slots:
    void reverseBoost();

public:

    Booster();
    void Boost();
};

#endif // BOOSTER_H
