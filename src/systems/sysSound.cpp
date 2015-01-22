#include "sysSound.h"


bool sysSound::Init()
{
    if(SDL_Init(SDL_INIT_AUDIO) != 0 )
    {
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,2048) != 0)
    {
        std::cerr << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}


void sysSound::Update()
{
}

void sysSound::Dispose()
{
}
