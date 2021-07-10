#include "Enemy.h"


void Enemy::update()
{
    GameObj::anim();
    y += 1;
    x += 1;
}


