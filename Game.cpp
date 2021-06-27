#include "Game.h"
#include <iostream>

using std::cout;
using std::endl;

bool Game::init(const char* title, int xpos, int ypos, int w, int h, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >=0)
    {
        cout << "SDL init success" << endl;
        m_pWnd = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
        if (m_pWnd!=0)
        {
            cout << "window creation success" << endl;
            m_pRdr = SDL_CreateRenderer(m_pWnd, -1, 0);

            if (m_pRdr)
            {
                cout << "render creation success" << endl;
                SDL_SetRenderDrawColor(m_pRdr, 255, 255, 255, 255);
                loadTex();
            } 
            else
            {
                cout << "renderer init failed" << endl;
                return false;
            }
        }
        else
        {
            cout << "renderer init failed" << endl;
            return false;
        }
    } 
    else
    {
        cout << "renderer init failed" << endl;
        return false;
    }

    cout << "init success" << endl;
    m_bRunning = true;
    //start main loop

    return true;
}

bool Game::init(const char* title, int xpos, int ypos, int w, int h, bool fullScreen)
{
    int flag = 0;

    if (fullScreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        cout << "SDL init success" << endl;
        m_pWnd = SDL_CreateWindow(title, xpos, ypos, w, h, flag);
        if (m_pWnd != 0)
        {
            cout << "window creation success" << endl;
            m_pRdr = SDL_CreateRenderer(m_pWnd, -1, 0);

            if (m_pRdr)
            {
                cout << "render creation success" << endl;
                SDL_SetRenderDrawColor(m_pRdr, 255, 255, 255, 255);
                loadTex();
            }
            else
            {
                cout << "renderer init failed" << endl;
                return false;
            }
        }
        else
        {
            cout << "renderer init failed" << endl;
            return false;
        }
    }
    else
    {
        cout << "renderer init failed" << endl;
        return false;
    }

    cout << "init success" << endl;
    m_bRunning = true;
    //start main loop

    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRdr);

    SDL_RenderCopy(m_pRdr, m_pTex, &m_sourceRectangle, &m_destinationRectangle);
    //SDL_RenderCopy(m_pRdr, m_pTex, nullptr, nullptr);
    SDL_RenderPresent(m_pRdr);
}

void Game::update()
{
    m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
}

void Game::handleEvent()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    cout << "cleaning game" << endl;
    SDL_DestroyWindow(m_pWnd);
    SDL_DestroyRenderer(m_pRdr);
    SDL_Quit();
}


void Game::loadTex()
{
    //const char path[]  = "Resource/banana.bmp";
    const char path[] = "Resource/animate.bmp";
    SDL_Surface* pTmpSurface = SDL_LoadBMP(path);
    m_pTex = SDL_CreateTextureFromSurface(m_pRdr, pTmpSurface);
    SDL_FreeSurface(pTmpSurface);
    SDL_QueryTexture(m_pTex, nullptr, nullptr, &m_sourceRectangle.w, &m_sourceRectangle.h);

    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;
    m_sourceRectangle.w = 128;
    m_sourceRectangle.h = 82;

    m_destinationRectangle.x = m_sourceRectangle.x;
    m_destinationRectangle.y = m_sourceRectangle.y;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
}
