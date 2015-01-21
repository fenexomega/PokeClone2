#ifndef ENGINE_H
#define ENGINE_H

#include "SDL2/SDL.h"
#include "gSystems.h"
#include "interfaces/iGame.h"
#include "util/uTime.h"


class Engine
{
public:
    static bool InitSystems();
    static int Run(iGame *game);
    static void ShutSystems();
};

#endif // ENGINE_H
