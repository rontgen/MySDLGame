#include "GameObj.h"
#include "TextureManager.h"

static TextureManager* g_sTM = TextureManager::instance();

GameObj::~GameObj()
{
}

void GameObj::load(int px, int py, int pw, int ph, std::string sTexId)
{
    x = px;
    y = py;
    w = pw;
    h = ph;
    m_sTexId = sTexId;
    m_curFrame = 1;
    m_curRow = 1;
}

void GameObj::draw(SDL_Renderer* pRender, SDL_RendererFlip flag)
{
    g_sTM->drawFrame(m_sTexId, x, y, w, h, m_curRow, m_curFrame, pRender, flag);

}

void GameObj::anim()
{
    m_curFrame = int((SDL_GetTicks() / 100) % 6);
}

void GameObj::update() 
{
    anim();
    x += 1;
}

void GameObj::clean() 
{

}
