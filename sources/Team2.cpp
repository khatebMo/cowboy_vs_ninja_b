#include "Team2.hpp"
#include"Team.hpp"
using namespace std;
#include <iostream>
namespace ariel{}
void Team2::add(Character *hero)
{
    if (hero->getPosition())
    {
        throw runtime_error("the leader is already in team!");
    }
    
    if (this->getGroup().size() >= 10)
    {
        throw runtime_error ("the team is already full");
    }
    if (hero->isAlive() && hero->getPosition() == false)
    {
        vector <Character*>temp=getGroup();
        temp.push_back(hero);
        setGroup(temp);
        hero->joinTeam();
    }
}