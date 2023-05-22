#include "Character.hpp"
#include "Point.hpp"
#include<iostream>
namespace ariel
{
}
Character::Character(string name, const Point &location) : name(name), location(location)
{
    this->inTeam=false;
}
Character ::~Character()
{
}
bool Character::isAlive()
{
    if (this->hp > 0)
    {
        return true;
    }

    return false;
}
double Character::distance( Character *other) const
{
    return this->location.distance(other->location);
}
void Character::hit(int num)
{
    if(num<0){
        throw invalid_argument("cant hit with nigative number!");
    }
    this->hp -= num;
}
string Character::getName()
{
    return this->name;
}
Point Character::getLocation()
{
    return this->location;
}


int Character::getHp(){
    return this->hp;
}
void Character:: setHp(int number){
    this->hp=number;
}
void Character::setLocation(const Point &newLocation){
    this->location=newLocation;
}
bool Character::getPosition(){
    return inTeam;
}
void Character::joinTeam(){
    this->inTeam=true;
}

