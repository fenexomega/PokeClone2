#ifndef MAP_H
#define MAP_H

#include <vector>

#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"

#include <map>
#include <iostream>

class Tilemap;

//TODO ajeitar essa classe monolitica

//TODO pegar w e h do mapa
class Map : public iGameObject
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
    iGameObject * player;

    std::vector<iGameObject *> gameObjects;
    std::vector<iGameObject *> gameEnemies;

    Vector2D<int> offset;
    Vector2D<int> tileSize;
    Vector2D<int> layerSize;

    std::vector<iGameObject *> npcs;

    Map(std::string jsonFile);
    ~Map();

    void Normalize(int x, int y);

    // iGameObject interface
    void Update(float dt);
    void Render();
    //

    void addGameObject(iGameObject *obj);
    void addGameEnemies(iGameObject *obj);


    Uint32 atPos(std::string stg,int x, int y);
    Rect atPosRect(int x, int y);

    Vector2D<int> getPlayerInitialPos() const;
    Vector2D<int> getOffset() const;
    void setOffset(const Vector2D<int> &value);
    std::vector<Rect> getLayersRect(std::string key);
    void setLayersRect(const std::map<std::string, std::vector<Rect> > &value);


};

#endif // WORLD_H
