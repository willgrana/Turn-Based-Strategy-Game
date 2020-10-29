#include "Enemy.h"
#include <stdlib.h>
#include <time.h>

Enemy::Enemy() {
    health = 0;
    attackValMin = 0;
    attackValMax = 0;
    blockValMin = 0;
    blockValMax = 0;
}

Enemy::Enemy(int h, int attackMin, int attackMax, int blockMin, int blockMax) {
    health = h;
    attackValMin = attackMin;
    attackValMax = attackMax;
    blockValMin = blockMin;
    blockValMax = blockMax;
}

int Enemy::decisionAB() {
    int decision;
    srand(time(NULL));
    decision = rand()%2;
    return decision;
}