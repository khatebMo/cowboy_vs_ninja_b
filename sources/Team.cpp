#include "Team.hpp"
#include "Character.hpp"
#include <vector>
#include <limits>
using namespace std;
#include <iostream>
#include <algorithm>

namespace ariel
{
}
Team::Team(Character *leader) : leader(leader)
{
    add(leader);
}
Team::~Team()
{
    for (Character *c : group)
    {
        delete (c);
    }
}
void Team::add(Character *hero)
{
    if (hero->getPosition())
    {
        throw runtime_error("the leader is already in team!");
    }
    if (group.size() >= 10)
    {
        throw runtime_error("the team is already full");
    }
    if (hero->isAlive() && hero->getPosition() == false)
    {
        group.push_back(hero);
        hero->joinTeam();
        sortTeam();
    }
}
void Team::attack(Team *other)
{
    if(other==nullptr){
        throw invalid_argument("the enemy team is null");

    }
    if (!other->stillAlive())
    {
        throw runtime_error("team is died");
    }
    if (!stillAlive())
    {
        throw runtime_error("team is died22");
    }
    if (!this->leader->isAlive())
    {
        chooseNewLeader();
    }
    Character *goal = chooseEnemyToAttack(other);
    for (Character *c : group)
    {
        if (!goal->isAlive() && c->isAlive())
        {
            if (!other->stillAlive())
            {
                return;
            }
            goal = chooseEnemyToAttack(other);
            c->attack(goal);
        }
        else if (goal->isAlive() && c->isAlive())
        {
            c->attack(goal);
        }
    }
}
void Team::print()
{
    for (Character *c : group)
    {
        cout << c->print() << endl;
    }
}
int Team::stillAlive()
{
    int count = 0;
    for (Character *c : group)
    {
        if (c->isAlive())
        {
            count++;
        }
    }

    return count;
}
void Team::chooseNewLeader()
{
    Character *newLeader = nullptr;
    double minDistance = numeric_limits<double>::max();

    for (Character *c : group)
    {
        double currentDistance = leader->distance(c);
        if (currentDistance < minDistance && c->isAlive())
        {
            minDistance = currentDistance;
            newLeader = c;
        }
    }
    this->leader = newLeader;
}
Character *Team::chooseEnemyToAttack(Team *enemy)
{
    if (enemy->stillAlive() < 1)
    {
        throw runtime_error("the team is already killed :~(");
    }

    Character *goal = nullptr;
    double minDistance = numeric_limits<double>::max();

    for (Character *c : enemy->group)
    {
        double currentDistance = leader->distance(c);
        if (currentDistance < minDistance && c->isAlive())
        {
            minDistance = currentDistance;
            goal = c;
        }
    }
    return goal;
}
void Team::sortTeam()
{
    vector<Character *> temp;
    for (Character *c : group)
    {
        if (Cowboy *cow = dynamic_cast<Cowboy *>(c))
        {
            temp.push_back(c);
        }
    }
    for (Character *c : group)
    {
        if (Ninja *nin = dynamic_cast<Ninja *>(c))
        {
            temp.push_back(c);
        }
    }
    this->group = temp;
}
void Team::setGroup(vector<Character *> team)
{
    this->group = team;
}
vector<Character *> Team::getGroup()
{
    return this->group;
}
