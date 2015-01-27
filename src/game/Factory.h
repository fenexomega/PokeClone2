#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

#include "game/objects/GameObject.h"
#include "game/objects/World.h"

#define OBJ_PLAYER 0
#define OBJ_ENEMY 1


class Factory
{
public:
    Factory();
    static GameObject *createPlayer(std::string jsonFile, World *world);
    ~Factory();
};

#endif // FACTORY_H
