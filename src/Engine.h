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
    std::vector<iSystem *> systems;
    bool InitSystems();
    void ShutSystems();
public:
    Engine();
    int Run(iGame *game);
};

#endif // ENGINE_H
