#ifndef ENGINE_H
#define ENGINE_H

#include "SDL2/SDL.h"
#include "interfaces/iGame.h"
#include "interfaces/iSystem.h"
#include "util/uTime.h"

#include <vector>

class Engine
{
private:
    static iGame *_game;

    static std::vector<iSystem *> systems;
    static  bool InitSystems();
    static void ShutSystems();
    Engine();
public:
    static int Run(iGame *game);
};

#endif // ENGINE_H
