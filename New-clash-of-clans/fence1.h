#ifndef FENCE1_H
#define FENCE1_H

#include <QDialog>

#include <QGraphicsItem>
#include <QPainter>
#include <QPushButton>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "health.h"

class Fence1 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    static qreal healthValue;

    Fence1(QString type);
    ~Fence1();
    bool remove;
    Health* fenceHealth;
    QString fenceType; //horizontal or vertical
    bool underRepair;
    void UpgradeButton();

private:
    QPixmap fenceImage;
    QPixmap upgradedFenceImage;
    int upgradeCost;
};

#endif // FENCE1_H
