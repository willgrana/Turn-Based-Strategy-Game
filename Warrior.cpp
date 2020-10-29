#include "Warrior.h"
#include <stdlib.h>
#include <time.h>

Warrior::Warrior() {
    health = 0;
    attackValMin = 0;
    attackValMax = 0;
    blockValMin = 0;
    blockValMax = 0;
    weapon;
}

int Warrior::getHealth() {
    return health;
}
void Warrior::setHealth(int h) {
    health = h;
}
int Warrior::getAttackValMin() {
    return attackValMin;
}
void Warrior::setAttackValMin(int a) {
    attackValMin = a;
}
int Warrior::getAttackValMax() {
    return attackValMax;
}
void Warrior::setAttackValMax(int a) {
    attackValMax = a;
}
int Warrior::getBlockValMin() {
    return blockValMin;
}
void Warrior::setBlockValMin(int b) {
    blockValMin = b;
}
int Warrior::getBlockValMax() {
    return blockValMax;
}
void Warrior::setBlockValMax(int b) {
    blockValMax = b;
}

Weapon Warrior::getWeapon() {
    return weapon;
}

void Warrior::setWeapon(Weapon w) {
    weapon = w;
}

int Warrior::getTurnAttack(Warrior w) {
    int attack;
    int floor;
    srand(time(NULL));
    floor = w.getAttackValMax()-w.getAttackValMin();
    attack = (rand()%floor) + w.getAttackValMin();
    return attack;
}

int Warrior::getTurnBlock(Warrior w) {
    int block;
    int floor;
    srand(time(NULL));
    floor = w.getBlockValMax()-w.getBlockValMin();
    block = (rand()%floor) + w.getBlockValMin();
    return block;
}



