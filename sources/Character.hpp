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
        // Default constructor
     Character() ;

    // Copy constructor
    Character(const Character& other) = default;

    // Copy assignment operator
    Character& operator=(const Character& other)= default;

    // Move constructor
    Character(Character&& other) = default;

    // Move assignment operator
    Character& operator=(Character&& other) noexcept = default;
    Character(const string& name,const Point &location);
    Character(const string& name,const Point &location,int hitp):name(name),location(location),hp(hitp),inTeam(false){}
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