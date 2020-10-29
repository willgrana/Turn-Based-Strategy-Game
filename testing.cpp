//
// Created by dylan on 2/18/2020.
//
#include "iostream"
#include "Warrior.h"
#include "Archer.h"
#include "Juggernaut.h"
#include "Enemy.h"

using namespace std;

Archer a;
Juggernaut j;
Enemy e = Enemy(60,5,20,4,10);

int getTurnAttack(Warrior w);
int getTurnBlock(Warrior w);

void testing();




int main(){
    testing();
    return 0;
}

void testing() {

    //warrior class testing
    //attacks
    int attack;
    attack = a.getTurnAttack(a);
    if (attack > a.getAttackValMax() or attack < a.getAttackValMin()) {
        cout << "getTurnAttack failed for Archer" << endl;
    }

    attack = j.getTurnAttack(j);
    if (attack > j.getAttackValMax() or attack < j.getAttackValMin()) {
        cout << "getTurnAttack failed for Juggernaut" << endl;
    }

    attack = e.getTurnAttack(e);
    if (attack > e.getAttackValMax() or attack < e.getAttackValMin()) {
        cout << "getTurnAttack failed for Enemy" << endl;
    }

    //blocks
    int block;
    block = a.getTurnBlock(a);
    if (block > a.getBlockValMax() or block < a.getBlockValMin()) {
        cout << "getTurnBlock failed for Archer" << endl;
    }

    block = j.getTurnBlock(j);
    if (block > j.getBlockValMax() or block < j.getBlockValMin()) {
        cout << "getTurnBlock failed for Juggernaut" << endl;
    }

    block = e.getTurnBlock(e);
    if (block > e.getBlockValMax() or block < e.getBlockValMin()) {
        cout << "getTurnBlock failed for Enemy" << endl;
    }

}