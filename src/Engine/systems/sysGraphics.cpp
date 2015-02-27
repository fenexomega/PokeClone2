#include "sysGraphics.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

bool sysGraphics::Init()
{

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    if(TTF_Init() < 0)
    {
        std::cerr << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}


void sysGraphics::Update()
{
}



void sysGraphics::Dispose()
{
}
