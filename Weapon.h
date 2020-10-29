

#ifndef CS120PROJECT3_WEAPON_H
#define CS120PROJECT3_WEAPON_H

class Weapon {
private:
    int damage;
    int block;
public:
    // Default Constructor
    // Requires: Nothing
    // Modifies: damage, block
    // Effects: Sets fields to default values
    Weapon();

    // Constructor
    // Requires: non-negative inputs
    // Modifies: damage, block
    // Effects: Sets fields
    Weapon(int d, int b);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    int getDamage();
    int getBlock();

    // Setters
    // Requires: Non-negative input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setDamage(int d);
    void setBlock(int b);

};

#endif //CS120PROJECT3_WEAPON_H
