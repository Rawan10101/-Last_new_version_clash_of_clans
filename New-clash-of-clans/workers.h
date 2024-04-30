#ifndef WORKERS_H
#define WORKERS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>

class Fence1;

class Workers : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Workers();
    void setFence(Fence1* fence);

signals:
    void fenceRepaired(Fence1* fence);

public slots:
    void rebuildStructure();

private:
    bool isDestroyed;
    Fence1* targetFence;
    void hideWorker();
    void showWorker();
};

#endif // WORKERS_H
