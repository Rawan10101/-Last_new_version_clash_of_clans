#include "bullet.h"
#include "troop.h"
#include "booster.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QDebug>
#include <QtMath>

Bullet::Bullet(qreal mouseX, qreal mouseY, qreal cannonX, qreal cannonY)
{
    this->mouseX = mouseX;
    this->mouseY = mouseY;
    this->cannonX = cannonX;
    this->cannonY = cannonY;

    QPixmap pixmap1(":/images/cannonball.png");
    pixmap1 = pixmap1.scaledToWidth(20);
    pixmap1 = pixmap1.scaledToHeight(20);
    setPixmap(pixmap1);
    speed = 5;

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move())); //timer to move bullet
    timer->start(30);
}

void Bullet::setDirection(qreal x, qreal y)
{
    qreal dx = x - this->x();
    qreal dy = y - this->y();

    qreal length = qSqrt(dx * dx + dy * dy);
    directionX = dx / length;
    directionY = dy / length;
}

void Bullet::move()
{
    qreal dx = mouseX - cannonX;
    qreal dy = mouseY - cannonY;
    qreal length = qSqrt(dx * dx + dy * dy);
    qreal x_inc = dx / length;
    qreal y_inc = dy / length;

    setPos(x() + x_inc*speed, y() + y_inc*speed);

    checkCollisions();

    if (y() < 0 || y() > scene()->height() || x() < 0 || x() > scene()->width()) //to remove bullet
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::checkCollisions()
{
    QList<QGraphicsItem*> colliding = collidingItems();
    foreach (QGraphicsItem* item, colliding)
    {
        if (typeid(*item) == typeid(Booster))
        {
            Booster* booster = dynamic_cast<Booster*>(item);
            booster->Boost();
        }
    }
}
