#ifndef WORKERS_H
#define WORKERS_H

#include "fence1.h"

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

// signals:
//     void fenceRepaired(Fence1* fence);

private:
    // bool isDestroyed;
    // void hideWorker();
    // void showWorker();
    void checkCollisions();
    void fixFence();


private slots:
    void move();

};

#endif // WORKERS_H
