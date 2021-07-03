/**
* Author:gwang
* Date: 2021-07-03
* Description: Game Object Base Class Related
*/

#pragma once

#include <string>
#include <SDL.h>

class GameObj
{
public:
    virtual void load(int x, int y, int w, int h, std::string sTexId);
    virtual void draw(SDL_Renderer* pRender, SDL_RendererFlip flag = SDL_FLIP_NONE);
    virtual void update();
    virtual void clean();
    virtual void anim();
protected:
    std::string m_sTexId;
    
    int m_curFrame;
    int m_curRow;

    int x;
    int y;

    int w;
    int h;
};
