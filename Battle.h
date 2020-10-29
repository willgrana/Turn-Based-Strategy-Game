

#ifndef CS120PROJECT3_BATTLE_H
#define CS120PROJECT3_BATTLE_H

#include "Enemy.h"

class Battle {
private:
    int turns;
public:

    // Default Constructor
    // Requires:nothing
    // Modifies:nothing
    // Effects: sets turns to 1
    Battle();


    // Requires: nothing
    // Modifies: nothing
    // Effects: returns enemy decision
    int getEnemyIntention(Enemy e);

    //getter
    // Requires: nothing
    // Modifies: nothing
    // Effects: returns turns
    int getTurns();

    // Requires: nothing
    // Modifies: nothing
    // Effects: adds to the number of turns
    void addTurn();

};

#endif //CS120PROJECT3_BATTLE_H
