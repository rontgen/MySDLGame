#include "TextureManager.h"
#include <SDL_image.h>

TextureManager* TextureManager::s_instance = nullptr;

TextureManager* TextureManager::instance()
{
    if (s_instance == nullptr)
    {
        s_instance = new TextureManager();
        return s_instance;
    }
    return s_instance;
}

bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer)
{
    auto pTmpSur = IMG_Load(fileName.c_str());
    if (!pTmpSur)
    {
        return false;
    }
    auto pTex = SDL_CreateTextureFromSurface(pRenderer, pTmpSur);
    SDL_FreeSurface(pTmpSur);
    if (pTex)
    {
        m_texMap[id] = pTex;
        return true;
    }
    return false;
}

void TextureManager::draw(string id, int x, int y, int w, int h, 
                            SDL_Renderer* pRenderer, SDL_RendererFlip flip /* = SDL_FLIP_NONE */)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_texMap[id], &srcRect, &destRect, 0, 0, flip);

}

void TextureManager::drawFrame(string id, int x, int y, int w, int h, int currentRow,
                            int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip /* = SDL_FLIP_NONE */)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = w * currentFrame;
    srcRect.y = h * (currentRow - 1);
    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;

    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_texMap[id], &srcRect, &destRect, 0, 0, flip);
}
