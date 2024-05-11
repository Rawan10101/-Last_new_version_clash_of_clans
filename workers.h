#ifndef WORKERS_H
#define WORKERS_H

#include "fence1.h"
#include "troop.h"
#include "townhall.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QTimer>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QVector2D>
#include <QCoreApplication>


class Workers : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Workers();
    // void setFence(Fence1* fence);
    Fence1* targetFence;
    QTimer* workerTimer;
    Townhall* home;
bool repaired();
    bool backHome=false;
// signals:
//     void fenceRepaired(Fence1* fence);

public slots:
    void dance();

private:
    // bool isDestroyed;
    // void hideWorker();
    // void showWorker();
    //void checkCollisions();

    bool isBeingRepaired();
    bool FenceAttacked();
    void fixFence();
    QTimer* danceTimer;
    QTimer* dTimer;
    bool dancing = false;


private slots:
    void move();
    void danceUtil();

};

#endif // WORKERS_H
