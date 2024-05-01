#include "workers.h"


Workers::Workers() : targetFence(nullptr)
{
    QPixmap workerImage(":/images/Worker.png");
    setPixmap(workerImage.scaled(30, 30));

    workerTimer = new QTimer();
    connect(workerTimer,SIGNAL(timeout()),this,SLOT (move()));
    // isDestroyed = false;
}


void Workers::move()
{
    // if worker is destroyed --> handle in troop collision
    // if their fence is destroyed --> go back to townhall
    // if they fixed their fence --> go back to townhall

    // move to the fence
    QPointF direction = targetFence->pos() - this->pos();
    direction /= QVector2D(direction).length();
    qreal dx = direction.x() * 10;
    qreal dy = direction.y() * 10;
    setPos(x() + dx, y() + dy);

    // checkCollisions(); //to handle if worker collided with the cannon

    if (collidesWithItem(targetFence)) //if worker has reached fence
    {
        fixFence();
    }
}

void Workers::checkCollisions()
{
    //handle cannon collisions here (redirect worker to move around cannon)
}
void Workers::fixFence()
{
    if (targetFence->fenceType == "vertical")
    {
        if (this->x() > targetFence->x()) //on the left fence
            this->setPos(x() + 20, y());
        else
            this->setPos(x() - 20, y());
    }
    else
    {
        if (this->y() > targetFence->y()) //on the top fence
            this->setPos(x(), y() + 20);
        else
            this->setPos(x(), y() - 20);
    }

    if (targetFence->fenceHealth->getHealth() < targetFence->fenceHealth->getMaxHealth())
        targetFence->fenceHealth->incrementHealth();

}


