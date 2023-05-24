#pragma once
#include "Character.hpp"
#include <vector>
#include "Point.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
namespace ariel
{
}
class Team
{
private:
    vector<Character *> group;
    Character *leader;

public:
    Team(Character *leader);
    
    virtual ~Team();
    void add(Character *hero);
    void attack(Team *other);
    int stillAlive();
    void print();
    void chooseNewLeader();
    virtual Character* chooseEnemyToAttack(Team *enemy);
    void sortTeam();
    void setGroup(vector<Character*>);
    Character* getLeader(){return leader;}
    vector<Character*> getGroup();
    int countNinja();
    int countCowBoys();
};   