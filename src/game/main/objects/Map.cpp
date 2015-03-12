#include "Map.h"

#include "io/FileLoader.h"

#include "util/Logger.h"

#include "graphics/Window.h"
#include "graphics/Tilemap.h"

Map::Map(std::string jsonFile)
{
    Json::Value root = FileLoader::LoadJson(jsonFile);
    tilemap = new Tilemap(root["TilemapJson"].asString());

    playerInitialPos.x = root["player"]["pos"][0].asInt();
    playerInitialPos.y = root["player"]["pos"][1].asInt();

    pos = playerInitialPos - 32;

    tileSize = tilemap->m_tileSize;
    layerSize = tilemap->getLayerSize();

    layersTiles["background"] = tilemap->getLayers(0);
    layersTiles["colidiveis"] = tilemap->getLayers(1);

    std::vector<Uint32> aux  = layersTiles["colidiveis"];
    for( Uint16 i = 0; i < aux.size() ; ++i)
        if( aux[i] != 0)
            layersRect["colidiveis"].push_back(tilemap->m_tileRects[i]);

    tileRects = tilemap->m_tileRects;

}

void Map::Normalize(int x, int y)
{
    playerDimensions.set(x,y);
    offset.set((Window::getWidth() - x)/2,
               (Window::getHeight() - y)/2);

}

Vector2D<int> Map::getPlayerInitialPos() const
{
    return playerInitialPos;
}



Vector2D<int> Map::getOffset() const
{
    return offset;
}

void Map::setOffset(const Vector2D<int> &value)
{
    offset = value;
}

std::vector<Rect> Map::getLayersRect(std::string key)
{
    return layersRect[key];
}

void Map::setLayersRect(const std::map<std::string, std::vector<Rect> > &value)
{
    layersRect = value;
}
std::string Map::getLocationDir(std::string filename)
{
    std::string aux;
    int i = filename.find_last_of('/');
    aux.append(filename.substr(0,i) + '/');
    return aux;
}

void Map::Render()
{
    tilemap->Render(pos + offset);
    for(iGameObject* i : gameObjects)
        i->Render();
    for(iGameObject* i : gameEnemies)
        i->Render();
    player->Render();
}

void Map::Move(Vector2D<int> acc)
{
    pos += acc;
}

void Map::setPos(Vector2D<int> pos)
{
    this->pos = pos;
}

void Map::addGameObject(iGameObject *obj)
{
    gameObjects.push_back(obj);
}

void Map::addGameEnemies(iGameObject *obj)
{
    gameEnemies.push_back(obj);
}

Uint32 Map::atPos(std::string stg, int x, int y)
{

    return layersTiles[stg][x + y*layerSize.x ];
}

Rect Map::atPosRect(int x, int y)
{
    return tileRects.at(x + y*layerSize.x);
}

void Map::Update(float dt)
{
    player->Update(dt);
    for(iGameObject* i : gameObjects)
        i->Update(dt);
    for(iGameObject* i : gameEnemies)
        i->Update(dt);

}


Map::~Map()
{
    for(iGameObject* i : gameObjects)
        delete i;
    for(iGameObject* i : gameEnemies)
        delete i;
    delete tilemap;
}

