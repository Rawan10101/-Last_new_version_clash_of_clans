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

Troop::Troop() {

    QPixmap picture(":/images/Barbarian1.png");
    picture = picture.scaledToHeight(40);
    picture = picture.scaledToWidth(40);
    this->setPixmap(picture);
    remove=false;
    speed = 1.0;

}

void Troop::stop() {
    stopped = true;
}
