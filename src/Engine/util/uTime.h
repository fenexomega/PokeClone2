#ifndef UTIME_H
#define UTIME_H
#include "SDL2/SDL.h"
#include <vector>


class uTime
{
private:
    long currentTime;
    long oldTime;
    float dt;
public:
    uTime();

    void Update();
    float getDeltaTime();
    void Delay(double s);


};

#endif // UTIME_H
