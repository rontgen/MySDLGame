#pragma once

#include <SDL.h>

class Game
{
public:
    Game()=default;
    ~Game()=default;
    void init() { m_bRunning = true; }
    bool init(const char* title, int xpos, int ypos, int w, int h, bool fullScreen);
    bool init(const char* title, int xpos, int ypos, int w, int h, int flags);
    void render();
    void update();
    void handleEvent();
    void clean();

    bool running() { return m_bRunning; }
private:
    void loadTex();
private:
    SDL_Window* m_pWnd;
    SDL_Renderer* m_pRdr;

    SDL_Texture* m_pTex;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;

    int m_curFrame;

    bool m_bRunning;
};
