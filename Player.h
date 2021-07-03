#pragma once

#include "GameObj.h"


class Player : public  GameObj
{
public:
    //void load(int x, int y, int w, int h, std::string sTexId) override;
    //void draw(SDL_Renderer* pRender) override;
    void update() override;
    //void clean() override;
};
