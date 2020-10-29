#include "Battle.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Battle::Battle() {
    turns = 1;
}

int Battle::getEnemyIntention(Enemy e) {
    int decision;
    decision = e.decisionAB();
    return decision;
};

int Battle::getTurns() {
    return turns;
}

void Battle::addTurn() {
    turns +=1;
}