#include "World.h"

#include "io/FileLoader.h"

#include "util/Logger.h"

#include "graphics/Window.h"


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
std::string World::getLocationDir(std::string filename)
{
    std::string aux;
    int i = filename.find_last_of('/');
    aux.append(filename.substr(0,i) + '/');
    return aux;

}

World::World(std::string jsonFile)
{
    Json::Value root = FileLoader::LoadJson(jsonFile);
    std::string Dir = getLocationDir(jsonFile);
    tilemap = new Tilemap(Dir + root["TilemapJson"].asString());

    playerInitialPos.x = root["PlayerPos"][0].asInt();
    playerInitialPos.y = root["PlayerPos"][1].asInt();

    pos = playerInitialPos - 32;

    tileSize = tilemap->m_tileSize;
    layerSize = tilemap->getLayerSize();

    layersTiles["background"] = tilemap->getLayers(0);
    layersTiles["colidiveis"] = tilemap->getLayers(1);
    layersTiles["objetos"] = tilemap->getLayers(2);

}

void World::Render()
{
    tilemap->Render(pos + offset);
}

Uint32 World::atPos(std::string stg, int x, int y)
{
    x /= layerSize.x;
    y /= layerSize.y;
    return layersTiles[stg][x + y*layerSize.x ];
}


World::~World()
{

}



void World::Update(float dt)
{
}
