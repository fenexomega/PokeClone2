#include "World.h"

#include "io/FileLoader.h"

#include "util/Logger.h"

#include "graphics/Window.h"
#include "graphics/Tilemap.h"

World::World(std::string jsonFile)
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

void World::Normalize(int x, int y)
{
    playerDimensions.set(x,y);
    offset.set((Window::getWidth() - x)/2,
               (Window::getHeight() - y)/2);

}

Vector2D<int> World::getPlayerInitialPos() const
{
    return playerInitialPos;
}



Vector2D<int> World::getOffset() const
{
    return offset;
}

void World::setOffset(const Vector2D<int> &value)
{
    offset = value;
}

std::vector<Rect> World::getLayersRect(std::string key)
{
    return layersRect[key];
}

void World::setLayersRect(const std::map<std::string, std::vector<Rect> > &value)
{
    layersRect = value;
}
std::string World::getLocationDir(std::string filename)
{
    std::string aux;
    int i = filename.find_last_of('/');
    aux.append(filename.substr(0,i) + '/');
    return aux;
}

void World::Render()
{
    tilemap->Render(pos + offset);
    for(iGameObject* i : gameObjects)
        i->Render();
}

void World::addGameObject(iGameObject *obj)
{
    gameObjects.push_back(obj);
}

Uint32 World::atPos(std::string stg, int x, int y)
{

    return layersTiles[stg][x + y*layerSize.x ];
}

Rect World::atPosRect(int x, int y)
{
    return tileRects.at(x + y*layerSize.x);
}

void World::Update(float dt)
{
    for(iGameObject* i : gameObjects)
        i->Update(dt);
}


World::~World()
{
    for(iGameObject* i : gameObjects)
        delete i;
}

