/**
* Author:gwang
* Date: 2021-07-03
* Description: Game State Related
*/

#pragma once

#include <SDL.h>
#include <vector>

class GameObj;


class Game
{
public:
    Game();
    ~Game();
    void init() { m_bRunning = true; }
    bool init(const char* title, int xpos, int ypos, int w, int h, bool fullScreen);
    bool init(const char* title, int xpos, int ypos, int w, int h, int flags);
    void render();
    void update();
    void handleEvent();
    void clean();
    void draw();
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

    GameObj* m_player = nullptr;
    GameObj* m_enemy1 = nullptr;
    GameObj* m_enemy2 = nullptr;
    GameObj* m_enemy3 = nullptr;

    GameObj* m_pGO = nullptr;
    GameObj* m_pPl = nullptr;
    GameObj* m_pEnemy = nullptr;

    std::vector<GameObj*> m_gameObj;
};
