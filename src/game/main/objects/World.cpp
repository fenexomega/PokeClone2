#include "World.h"

#include "game/main/objects/Map.h"

Map *World::actualMap() const
{
    return _actualMap;
}

void World::setActualMap(Map *world)
{
    _actualMap = world;
}

void World::setActualMap(std::string mapName)
{
    for(Map* i : _maps)
    {
        if(i->name == mapName)
            _actualMap = i;
    }
}

void World::addMap(Map *map)
{
    _maps.push_back(map);
}

Map *World::at(int i)
{
    return _maps.at(i);
}

World::World()
{

}

World::~World()
{
    for(auto i : _maps)
        delete i;
    _maps.clear();
}



void World::Update(float dt)
{
    _actualMap->Update(dt);
}

void World::Render()
{
    _actualMap->Render();
}
