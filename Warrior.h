//
// Created by Will Grana on 2/10/20.
//

#ifndef CS120PROJECT3_WARRIOR_H
#define CS120PROJECT3_WARRIOR_H

#include "Weapon.h"


class Warrior {
protected:
    int health;
    int attackValMin;
    int attackValMax;
    int blockValMin;
    int blockValMax;
    Weapon weapon;

public:
    // Default Constructor
    // Requires: Nothing
    // Modifies: health, attackValMax, attackValMin, blockValMax, blockValMin, weapon
    // Effects: Sets fields to default values
    Warrior();

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    int getHealth();
    int getAttackValMin();
    int getAttackValMax();
    int getBlockValMin();
    int getBlockValMax();
    Weapon getWeapon();
    int getTurnAttack(Warrior w);
    int getTurnBlock(Warrior w);

    // Setters
    // Requires: Non-negative input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setHealth(int h);
    void setAttackValMin(int a);
    void setAttackValMax(int a);
    void setBlockValMin(int b);
    void setBlockValMax(int b);
    void setWeapon(Weapon w);
};

#endif //CS120PROJECT3_WARRIOR_H
