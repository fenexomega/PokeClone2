#include "uTime.h"

uTime::uTime()
{
    currentTime = oldTime = SDL_GetTicks();
}

void uTime::Update()
{
    oldTime = currentTime;
    currentTime = SDL_GetTicks();
    dt = (currentTime - oldTime)/1000.0f;
}

float uTime::getDeltaTime()
{
    return dt;
}
