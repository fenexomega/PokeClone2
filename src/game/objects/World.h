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
private:
    Tilemap *tilemap;
    Vector2D<int> pos;
    Vector2D<int> playerInitialPos;
    Vector2D<int> playerDimensions;

    std::string getLocationDir(std::string filename);
public:
    std::vector<iGameObject *> npcs;

    World(std::string jsonFile);
    void Render();
    ~World();
    Vector2D<int> getPlayerDimensions() const;
    void setPlayerDimensions(int x, int y);
};

#endif // WORLD_H
