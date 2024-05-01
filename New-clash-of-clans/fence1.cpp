#include "fence1.h"
#include "troop.h"
#include <QTimer>
#include <QList>
#include <QDebug>
#include <QPixmap>
#include<QObject>
#include<QGraphicsScene>
// #include<game.h>
Fence1::Fence1(QString type)
{
    QPixmap pixmap(":/images/Wall.png");
    pixmap = pixmap.scaledToWidth(50);
    pixmap = pixmap.scaledToHeight(50);
    this->setPixmap(pixmap);
    fenceHealth = new Health();
    fenceType = type;
    remove=false;
}

Fence1::~Fence1()
{
}
