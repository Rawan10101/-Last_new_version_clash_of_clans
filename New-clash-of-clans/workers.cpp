#include "workers.h"
#include "troop.h"
#include "game.h"
#include <QRandomGenerator>
#include <QGraphicsItem>



Workers::Workers() : targetFence(nullptr)
{
    QPixmap workerImage(":/images/Worker.png");
    setPixmap(workerImage.scaled(30, 30));

    workerTimer = new QTimer();
    connect(workerTimer,SIGNAL(timeout()),this,SLOT (move()));
    // isDestroyed = false;
}

//check if the fence is repaired
bool Workers::repaired()
{
    if (targetFence && targetFence->fenceHealth->getHealth() == targetFence->fenceHealth->getMaxHealth())
        return true;
    else
        return false;
}


// void Workers::move()
// {
//     // if worker is destroyed --> handle in troop collision

//     // if their fence is destroyed --> go back to townhall
//     // if they fixed their fence --> go back to townhall

//     // move to the fence
//     QPointF direction = targetFence->pos() - this->pos();
//     direction /= QVector2D(direction).length();
//     qreal dx = direction.x() * 10;
//     qreal dy = direction.y() * 10;
//     setPos(x() + dx, y() + dy);

//     // checkCollisions(); //to handle if worker collided with the cannon

//     if (collidesWithItem(targetFence)) //if worker has reached fence
//     {
//         fixFence();
//     }
// }

void Workers::move()
{
    // if(!repaired())
    // {
        // If the worker is repairing, move towards the fence
        QPointF direction = targetFence->pos() - this->pos();
        direction /= QVector2D(direction).length();
        qreal dx = direction.x() * 10;
        qreal dy = direction.y() * 10;
        setPos(x() + dx, y() + dy);

        if (collidesWithItem(targetFence))
        {
            fixFence();
        }


        else
    {
            qreal dx = home->x() - this->x();
            qreal dy = home->y() - this->y();
        qreal dist = std::sqrt(dx * dx + dy * dy);

        // Move towards the town hall in small increments
        if (dist > 1.0)
        {
            dx /= dist;
            dy /= dist;
            setPos(x() + dx * 10, y() + dy * 10);
        }
        else
        {
            // Once the worker reaches the town hall, remove the worker and decrement the number of workers
            backHome==true; // Assuming workerCount is a global variable tracking the number of workers
        }



}
    }


// void Workers::checkCollisions()
// {
//     //handle cannon collisions here (redirect worker to move around cannon)


// }



// void Workers::fixFence()
// {
//     if (targetFence->fenceType == "vertical")
//     {
//         if (this->x() > targetFence->x()) //on the left fence
//             this->setPos(x() + 20, y());
//         else
//             this->setPos(x() - 20, y());


//     }
//     else
//     {
//         if (this->y() > targetFence->y()) //on the top fence
//             this->setPos(x(), y() + 20);
//         else
//             this->setPos(x(), y() - 20);
//     }

//     if (targetFence->fenceHealth->getHealth() < targetFence->fenceHealth->getMaxHealth())
//     {
//         targetFence->fenceHealth->incrementHealth();
//     }

void Workers::fixFence()
{
    // Implement fence fixing logic as before
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

            if (targetFence->fenceHealth->getHealth() < targetFence->fenceHealth->getMaxHealth()) {
                targetFence->fenceHealth->incrementHealth();
            }






            // else

            // {
            //     // If the fence is fully repaired, switch to strolling mode
            //     isRepairing = false;
            // }
}













