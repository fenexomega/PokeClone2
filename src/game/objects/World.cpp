#include "World.h"


World::World(std::string jsonFile)
{
    tilemap = new Tilemap(jsonFile);
}

World::~World()
{

}

