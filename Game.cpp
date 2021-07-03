#include "Game.h"
#include <iostream>
#include <SDL_image.h>
#include <string>
#include "TextureManager.h"
#include "Player.h"

using std::string;
using std::cout;
using std::endl;

static string g_sAnim = "animate";

Game::Game()
    : m_bRunning(true)
{
    m_pGO = new GameObj();
    m_pPl = new Player();
}

Game::~Game()
{
    if (m_pGO)
    {
        delete m_pGO;
        m_pGO = nullptr;
    }
    if (m_pPl)
    {
        delete m_pPl;
        m_pPl = nullptr;
    }
}

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

    m_pGO->load(100, 100, 128, 82, g_sAnim);
    m_pPl->load(300, 300, 128, 82, g_sAnim);
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
                SDL_SetRenderDrawColor(m_pRdr, 255, 0, 0, 255);
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
    m_pGO->load(100, 100, 128, 82, g_sAnim);
    m_pPl->load(300, 300, 128, 82, g_sAnim);
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRdr);

    //SDL_RenderCopy(m_pRdr, m_pTex, &m_sourceRectangle, &m_destinationRectangle);
    //SDL_RenderCopy(m_pRdr, m_pTex, nullptr, nullptr);
    //SDL_RenderCopyEx(m_pRdr, m_pTex, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    //TextureManager::instance()->draw("animate", 0, 0, 128, 82, m_pRdr);
    //TextureManager::instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_curFrame, m_pRdr);
    m_pGO->draw(m_pRdr);
    m_pPl->draw(m_pRdr, SDL_FLIP_HORIZONTAL);
    
    SDL_RenderPresent(m_pRdr);
}

void Game::update()
{
    //m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
    //m_curFrame = int((SDL_GetTicks() / 100) % 6);
    m_pGO->update();
    m_pPl->update();
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
    const char bmpPath[] = "Resource/animate.bmp";
    string pngPath("Resource/animate-alpha.png");
    //SDL_Surface* pTmpSurface = SDL_LoadBMP(bmpPath);
//     SDL_Surface* pTmpSurface = IMG_Load(pngPath);
//     m_pTex = SDL_CreateTextureFromSurface(m_pRdr, pTmpSurface);
//     SDL_FreeSurface(pTmpSurface);
//     SDL_QueryTexture(m_pTex, nullptr, nullptr, &m_sourceRectangle.w, &m_sourceRectangle.h);
// 
//     m_sourceRectangle.x = 0;
//     m_sourceRectangle.y = 0;
//     m_sourceRectangle.w = 128;
//     m_sourceRectangle.h = 82;
// 
//     m_destinationRectangle.x = m_sourceRectangle.x;
//     m_destinationRectangle.y = m_sourceRectangle.y;
//     m_destinationRectangle.w = m_sourceRectangle.w;
//     m_destinationRectangle.h = m_sourceRectangle.h;
    TextureManager::instance()->load(pngPath,"animate",  m_pRdr);
}
