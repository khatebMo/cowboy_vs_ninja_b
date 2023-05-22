#include "Ninja.hpp"
#include "Point.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel
{
}
Ninja::Ninja(string name, const Point &location) : Character(name, location)
{
}
Ninja::~Ninja() {}
void Ninja::move(Character *other)
{
    this->setLocation(this->getLocation().moveTowards(this->getLocation(), other->getLocation(), this->getSpeed()));
}
void Ninja::slash(Character *other)
{
    if (other == nullptr)
    {
        throw runtime_error("the enemy is null!");
    }
    if (this == other)
    {
        throw runtime_error("this is the same cowboy");
    }
    if (!other->isAlive())
    {
        throw runtime_error("the enemy is already died!");
    }
    if (!isAlive())
    {
        throw runtime_error("the hero is already died!");
    }
    if (this->distance(other) < 1 && isAlive() && other->isAlive())
    {
        other->hit(40);
    }
}
string Ninja::print()
{
    if (!isAlive())
    {
        return '(' + this->getName() + ')';
    }
    else
    {
        return "(N)  name: " + this->getName() + "\nhP: " + to_string(this->getHp()) + "\nlocation: " + this->getLocation().toString() + "\n";
    }
}
void Ninja::setSpeed(int speed)
{
    this->speed = speed;
}
int Ninja::getSpeed()
{
    return speed;
}
void Ninja::attack(Character *other)
{
    if (this->distance(other) >= 1)
    {
        move(other);
    }
    else
    {
        slash(other);
    }
}
