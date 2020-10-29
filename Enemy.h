

#ifndef CS120PROJECT3_ENEMY_H
#define CS120PROJECT3_ENEMY_H

#include "Warrior.h"

class Enemy : public Warrior {
public:
    // Default Constructor
    // Requires: nothing
    // Modifies:health, attackValMax, attackValMin, blockValMax, blockValMin
    // Effects: sets all stats to zero
    Enemy();

    //Constructor
    // Requires: nothing
    // Modifies:health, attackValMax, attackValMin, blockValMax, blockValMin
    // Effects: sets all stats to default
    Enemy(int h, int attackMin, int attackMax, int blockMin, int blockMax);


    // Requires: nothing
    // Modifies: nothing
    // Effects: returns enemy decision
    int decisionAB();
};

#endif //CS120PROJECT3_ENEMY_H
