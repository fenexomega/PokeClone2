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
    //TODO fazer esse delta time direito
    double value = (1000.0f/60.0f)/1000.0f;
//    LOG("DT = " + TOSTR(dt) + " | VALUE =  " + TOSTR(value));
    return dt >= value ? dt : value ;
//    return dt;
}
