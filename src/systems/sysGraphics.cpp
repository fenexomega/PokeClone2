#include "sysGraphics.h"


bool sysGraphics::Init()
{

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        uLOG("ERROR: Graphics cannot be initialized.\n " << SDL_GetError());
        return false;
    }
    return true;
}

void sysGraphics::Update()
{
//    SDL_RenderPresent(renderer);
}

void sysGraphics::renderTexture(SDL_Texture *texture, SDL_Rect rect)
{
//    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void sysGraphics::Shut()
{
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(screen);
}

void sysGraphics::clearScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
//    SDL_SetRenderDrawColor(renderer,r,g,b,a);
//    SDL_RenderClear(renderer);
}


