#include "World.h"

#include "io/FileLoader.h"

#include "util/Logger.h"


Vector2D<int> World::getPlayerDimensions() const
{
    return playerDimensions;
}

void World::setPlayerDimensions(int x, int y)
{
    playerDimensions.set(x,y);
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

}

void World::Render()
{
    tilemap->Render(pos);
}

World::~World()
{

}

