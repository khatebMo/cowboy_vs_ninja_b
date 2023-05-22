#pragma once
#include "Character.hpp"
namespace ariel
{
}
class Ninja : public Character
{
private:
    int speed;

public:
    Ninja(string name, const Point &location);
    Ninja(string name, const Point &location,int speed,int hp):Character(name,location,hp),speed(speed){}
    ~Ninja();
    virtual void move(Character *other);
    virtual void slash(Character *other);
    string print();
    void setSpeed(int speed);
    int getSpeed();
    void attack(Character *other);
    string getType(){return "Ninja";}
};