#include "Weapon.h"

Weapon::Weapon() {
    damage = 0;
    block = 0;
}

Weapon::Weapon(int d, int b) {
    damage = d;
    block = b;

}

int Weapon::getDamage() {
    return damage;
}
void Weapon::setDamage(int d) {
    damage = d;
}
int Weapon::getBlock() {
    return block;
}
void Weapon::setBlock(int b) {
    block = b;
}