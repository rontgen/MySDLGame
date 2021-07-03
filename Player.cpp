#include "Player.h"
#include "SDL.h"

// void Player::draw(SDL_Renderer* pRender)
// {
// 
// }
void Player::update()
{
    GameObj::anim();
    x -= 1;
}

// void Player::clean()
// {}
