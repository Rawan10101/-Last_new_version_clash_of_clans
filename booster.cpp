#include "booster.h"

Booster::Booster()
{
    QPixmap pixmap(":/images/booster.png");
    pixmap = pixmap.scaledToWidth(30);
    pixmap = pixmap.scaledToHeight(30);
    setPixmap(pixmap);
    timer = new QTimer;

    connect(timer, SIGNAL(timeout()), this, SLOT(reverseBoost()));

}

void Booster::Boost()
{
    tempCannon = new Cannon;
    // originalPower = tempCannon->power;

    tempCannon->currPower += tempCannon->power * 0.5;
    qDebug() << "boosted " <<  tempCannon->currPower;

    this->hide();
    timer->start(30000);

}

void Booster::reverseBoost()
{
    tempCannon->currPower = tempCannon->power;
    qDebug() << "power back to:  " << tempCannon->power;
    delete tempCannon;
    delete this;
}
