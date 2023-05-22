#include "Cowboy.hpp"
#include "Point.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel
{
}
Cowboy::Cowboy(string name, const Point &location) : Character(name, location), bollets(6)
{
    this->setHp(110);
}
Cowboy::~Cowboy() {}
void Cowboy::shoot(Character *other)
{

    if (other == nullptr)
    {
        throw runtime_error("the enemy is null!");
    }
    if(this==other){
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

    if (this->getHp() > 0 && this->hasboolets())
    {
        other->hit(10);
        this->bollets--;
    }
    else if (!hasboolets())
    {
        reload();
    }
}
bool Cowboy::hasboolets()
{
    if (this->bollets > 0)
    {
        return true;
    }
    return false;
}
void Cowboy::reload()
{
    if (isAlive())
    {
        this->bollets = 6;
    }else{
        throw runtime_error("died cowboy can't reload!");
    }
}
string Cowboy::print()
{
    if (!isAlive())
    {
        return '(' + this->getName() + ')';
    }
    else
    {
        return "(C)  name: " + this->getName() + "\nhP: " + to_string(this->getHp()) + "\nlocation: " + this->getLocation().toString() + "\n";
    }
}
void Cowboy::attack(Character *other)
{
    shoot(other);
}
