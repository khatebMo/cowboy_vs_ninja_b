#pragma once
#include"Team.hpp"
class SmartTeam : public Team{
    SmartTeam(Character *leader):Team(leader){}
    void attack(Team *other);
    Character * chooseCoLeader(Team* other);
    void smartSort(Team* other);
    int countReadyHero(Team* other);
};