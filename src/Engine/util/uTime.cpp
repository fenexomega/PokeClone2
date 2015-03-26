#include "uTime.h"

#include "util/Logger.h"

uTime::uTime()
{
    currentTime = oldTime = SDL_GetTicks();
}

void uTime::Update()
{
    oldTime = currentTime;
    currentTime = SDL_GetTicks();
    dt = (currentTime - oldTime)/1000.0f;
//    PRINT(dt);

}

float uTime::getDeltaTime()
{

    return dt;
}

void uTime::Delay(double s)
{
    SDL_Delay(s);
}
