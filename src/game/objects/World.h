#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "interfaces/iGameObject.h"
#include "graphics/Tilemap.h"
#include "math/Vector2D.h"
#include <map>


#include <iostream>

//TODO pegar w e h do mapa
//TODO pegar layers
class World : public iGameObject
{
private:
    Tilemap *tilemap;
    Vector2D<int> offset;
    Vector2D<int> playerInitialPos;
    Vector2D<int> playerDimensions;
    Vector2D<int> tileSize;

    std::map<std::string,std::vector<Uint32> > layersTiles;

    std::string getLocationDir(std::string filename);
public:
    Vector2D<int> layerSize;
    std::vector<iGameObject *> npcs;

    World(std::string jsonFile);
    ~World();

    void Normalize(int x, int y);

    // iGameObject interface
    void Update(float dt);
    void Render();

    Uint32 atPos(std::string stg,int x, int y);
    Vector2D<int> getPlayerInitialPos() const;
    Vector2D<int> getOffset() const;
    void setOffset(const Vector2D<int> &value);
};

#endif // WORLD_H
