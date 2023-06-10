#pragma once
#include "Character.hpp"
namespace ariel
{
}
class Cowboy : public Character
{
private:
    int bollets;

public:
    Cowboy();

    // Copy constructor
    Cowboy(const Cowboy &other);

    // Copy assignment operator
    Cowboy &operator=(const Cowboy &other);

    // Move constructor
    Cowboy(Cowboy &&other) noexcept;

    // Move assignment operator
    Cowboy &operator=(Cowboy &&other) noexcept;

    Cowboy(string name, const Point &lacation);
    ~Cowboy();
    void shoot(Character *other);
    bool hasboolets();
    void reload();
    string print()override;
    void attack(Character *other)override;
    string getType() override{ return "Cowboy"; }
    
    
};