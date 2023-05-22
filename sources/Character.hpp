#pragma once

#include <string>
#include "Point.hpp"
namespace ariel{}
using namespace std;
class Character
{
private:
    Point location;
    int hp;
    string name;
    bool inTeam;

public:

    Character(string name,const Point &location);
    Character(string name,const Point &location,int hp):name(name),location(location),hp(hp){}
    virtual ~Character();
    bool isAlive();
    double distance( Character *other) const;
    void hit(int num);
    string getName();
    Point getLocation();
    int getHp();
    void setHp(int number);
    virtual string print()=0;
    void setLocation(const Point &newLocation);
    bool getPosition();
    void joinTeam();
    virtual void attack(Character *other)=0;
    virtual string getType()=0;
};