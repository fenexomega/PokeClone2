#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"

#include <map>
#include <iostream>

class Tilemap;

//TODO pegar w e h do mapa
class World : public iGameObject
{
private:
    Tilemap *tilemap;
    Vector2D<int> playerInitialPos;
    Vector2D<int> playerDimensions;

    std::vector<Rect>tileRects;

    std::map<std::string,std::vector<Uint32> > layersTiles;
    std::map<std::string,std::vector<Rect> > layersRect;

    std::string getLocationDir(std::string filename);

public:
    std::vector<iGameObject *> gameObjects;

    Vector2D<int> offset;
    Vector2D<int> tileSize;
    Vector2D<int> layerSize;

    std::vector<iGameObject *> npcs;

    World(std::string jsonFile);
    ~World();

    void Normalize(int x, int y);

    // iGameObject interface
    void Update(float dt);
    void Render();
    //

    void addGameObject(iGameObject *obj);

    Uint32 atPos(std::string stg,int x, int y);
    Rect atPosRect(int x, int y);

    Vector2D<int> getPlayerInitialPos() const;
    Vector2D<int> getOffset() const;
    void setOffset(const Vector2D<int> &value);
    std::vector<Rect> getLayersRect(std::string key);
    void setLayersRect(const std::map<std::string, std::vector<Rect> > &value);


};

#endif // WORLD_H
