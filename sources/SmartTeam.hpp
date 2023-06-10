#pragma once
#include "Team.hpp"
class SmartTeam : public Team
{
private:
public:
    SmartTeam(Character *);
    void attack(Team *enemyTeam);   // override attack function
    void add(Character *newMember); // override add function

    // The chooseVictim() function selects the victim for the attacker based on their proximity
    Character *chooseVictim(Character *, Team *);
};
