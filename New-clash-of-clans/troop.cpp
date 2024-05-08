#include "troop.h"
#include "fence1.h"
#include "townhall.h"
#include "health.h"
#include "cannon.h"
#include <QRandomGenerator>
#include <QDebug>
#include<QTimer>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QPushButton>
#include <QCoreApplication>
#include <iostream>
#include <QRandomGenerator>
#include<QObject>

Troop::Troop(int value) {

    QPixmap picture(":/images/Barbarian1.png");
    picture = picture.scaledToHeight(40);
    picture = picture.scaledToWidth(40);
    this->setPixmap(picture);
    remove=false;
    speed = 1.0;
    troopHealth = new Health(value);
    danceTimer = new QTimer;
    connect(danceTimer, SIGNAL(timeout()), this, SLOT(dance()));
    dTimer = new QTimer;
    connect(dTimer, SIGNAL(timeout()), this, SLOT(danceUtil()));
    dTimer->start(300);
}

void Troop::dance()
{
    dancing = true;
    danceTimer->start(300);
    setPos(x(), y()-15);

}

void Troop::danceUtil()
{
    if (dancing)
        setPos(x(), y()+15);
}

void Troop::knockBack(qreal X, qreal Y)
{
    qreal dx = X - this->pos().x();
    qreal dy = Y - this->pos().y();

    setPos(x() - dx, y() - dy);
}
