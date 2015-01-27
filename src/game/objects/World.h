#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "interfaces/iGameObject.h"
#include "graphics/Tilemap.h"
#include "math/Vector2D.h"

#include <iostream>

//TODO terminar essa classe
class World
{
public:
    Tilemap *tilemap;
    std::vector<iGameObject *> npcs;
    Vector2D<int> playerInitialPos;
    World(std::string jsonFile);
    ~World();
};

#endif // WORLD_H
