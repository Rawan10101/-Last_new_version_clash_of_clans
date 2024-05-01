#include "workers.h"
#include "fence1.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>

Workers::Workers() : isDestroyed(false), targetFence(nullptr)
{
    QPixmap workerImage(":/images/Worker.png");
    setPixmap(workerImage.scaled(30, 30));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(rebuildStructure()));
    timer->start(300);
}

void Workers::setFence(Fence1* fence)
{
    targetFence = fence;
}

void Workers::rebuildStructure()
{
    if (!isDestroyed || targetFence == nullptr)
    {
        hide();
        return;
    }

    show();

    // Move the worker towards the target fence
    qreal dx = targetFence->x() - x();
    qreal dy = targetFence->y() - y();

    if (qAbs(dx) > qAbs(dy))
    {
        if (dx < 0)
            setPos(x() - 10, y()); // Move left
        else
            setPos(x() + 10, y()); // Move right
    }
    else
    {
        if (dy < 0)
            setPos(x(), y() - 10); // Move up
        else
            setPos(x(), y() + 10); // Move down
    }

    // Check if the worker has reached the target fence
    if (collidesWithItem(targetFence))
    {
        emit fenceRepaired(targetFence); // Emit signal to repair the fence

        // Reset the state of the worker
        targetFence = nullptr;
        isDestroyed = false;
        hide();
    }
}
void Workers::hideWorker()
{
    setVisible(false);
}

void Workers::showWorker()
{
    setVisible(true);
}
