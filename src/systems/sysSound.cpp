#include "sysSound.h"

sysSound::sysSound()
{
}

bool sysSound::Init()
{
    if(SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        uLOG(SDL_GetError());
        return false;
    }
    return true;
}
