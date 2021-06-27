#pragma once

#include <string>
#include <map>

#include <SDL.h>

using std::string;
using std::map;
class TextureManager
{
public:
    bool load(string fileName, string id, SDL_Renderer* pRenderer);
    void draw(string id, int x, int y, int w, int h,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(string id, int x, int y, int w, int h, int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    map<string, SDL_Texture*> m_texMap;
};
