#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

void init();
bool init(const char* title, int xpos, int ypos, int w, int h, int flags);
void render(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void update();
void handleEvent();
void clean();

int main(int argc, char* argv[])
{
    if (init("My SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,480, SDL_WINDOW_SHOWN))
    {
        g_bRunning = true;
    }
    else
    {
        return 1;
    }
    while (g_bRunning)
    {
        render(0, 0, 0, 255);
    }
    SDL_Quit();
    return 0;
}


bool init(const char* title, int xpos, int ypos, int w, int h, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >=0)
    {
        g_pWindow = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
        if (g_pWindow!=0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    } 
    else
    {
        return false;
    }
    return true;
}

void render(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(g_pRenderer, r, g, b, a);
    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);
}

void update()
{}

void handleEvent()
{}

void clean()
{
}
