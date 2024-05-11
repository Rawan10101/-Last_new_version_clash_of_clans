#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>

class Health : public QObject
{
    Q_OBJECT

public:
    Health();
    Health(qreal value);

    qreal getHealth();
    qreal getMaxHealth();
    void setMaxHealth(qreal newMaxHealth);
    void reduceHealth(qreal value);
    void incrementHealth();


private:
    qreal maxHealth;
    qreal health;
};

#endif // HEALTH_H
