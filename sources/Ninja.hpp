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
    // Ninja(string name, const Point &location,int speed,int hitp):Character(name,location,hitp),speed(speed){}
    ~Ninja() override;
    virtual void move(Character *other);
    virtual void slash(Character *other);
    string print() override;
    void setSpeed(int speed);
    int getSpeed();
    void attack(Character *other) override;
    string getType() override { return "Ninja"; }
    void retreat();
    
};