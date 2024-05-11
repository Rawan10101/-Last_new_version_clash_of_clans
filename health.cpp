#include "health.h"

Health::Health()
{
    maxHealth = 10;
    health = maxHealth;
}

Health::Health(qreal value)
{
    maxHealth = value;
    health = maxHealth;
}

qreal Health::getHealth() {
    return health;
}

qreal Health::getMaxHealth() {
    return maxHealth;
}

void Health::setMaxHealth(qreal newMaxHealth) {
    maxHealth = newMaxHealth;
    health = maxHealth;

}

void Health::reduceHealth(qreal value) {
    health -= value;
}

void Health::incrementHealth() {
    health += 1;
}
