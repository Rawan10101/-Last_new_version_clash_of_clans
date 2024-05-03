#include "health.h"

Health::Health()
{
    maxHealth = 10;
   health = maxHealth;
}

Health::Health(int value)
{
    maxHealth = value;
    health = maxHealth;
}

int Health::getHealth() {
    return health;
}

int Health::getMaxHealth() {
    return maxHealth;
}

void Health::setMaxHealth(int newMaxHealth) {
    maxHealth = newMaxHealth;
    health = maxHealth;

}

void Health::decrementHealth() {
    health-=1;
}

void Health::incrementHealth() {
    health += 1;
}
