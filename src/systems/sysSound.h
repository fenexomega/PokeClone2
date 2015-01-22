#ifndef SYSSOUND_H
#define SYSSOUND_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "interfaces/iSystem.h"


class sysSound : public iSystem
{
public:
    // iSystem interface
    bool Init();
    void Update();
    void Dispose();
};

#endif // SOUND_H
