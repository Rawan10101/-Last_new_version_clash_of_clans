#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDialog>
#include "cannon.h"
#include "bullet.h"
#include "health.h"
#include <QGraphicsRectItem>
#include <QTimer>

Cannon::Cannon()
{
   QPixmap pixmap(":/images/Cannon.png");
   pixmap = pixmap.scaledToWidth(100);
   pixmap = pixmap.scaledToHeight(100);
   this->setPixmap(pixmap);
}

qreal Cannon::power = 100;
qreal Cannon::currPower = 100;

void Cannon::powerUp()
{
    power += power * 0.1; //power upgrades by 10% each 20 kills
    currPower += power * 0.1;
}

void Cannon::Upgrade()
{
    QPixmap pixmap(":/images/Castle.png");
    pixmap = pixmap.scaledToWidth(50);
    pixmap = pixmap.scaledToHeight(50);
    this->setPixmap(pixmap);
    cannonHealth->setMaxHealth(15);
}
