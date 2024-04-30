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

    emit fenceRepaired(targetFence);

    // Reset the state of the worker
    targetFence = nullptr;
    isDestroyed = false;
    hide();
}

void Workers::hideWorker()
{
    setVisible(false);
}

void Workers::showWorker()
{
    setVisible(true);
}
