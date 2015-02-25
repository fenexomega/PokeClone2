#include "World.h"

#include "game/main/objects/Map.h"
#include "game/main/objects/GameObject.h"

Map *World::actualMap() const
{
    return _actualMap;
}

Map *World::findMapByName(std::string mapName)
{
    for(Map* i : _maps)
    {
        if(i->name == mapName)
            return i;
    }
    return nullptr;
}

void World::setActualMap(Map *map)
{
    _actualMap = map;

}

void World::setActualMap(std::string mapName, Vector2D<int> playerPos)
{
    _actualMap = findMapByName(mapName);
    _actualMap->pos = -playerPos;
    GameObject *player = dynamic_cast<GameObject*>(_actualMap->player);
    player->pos = playerPos;
    player->setMap(_actualMap);

}

void World::addMap(Map *map)
{
    _maps.push_back(map);
}

Map *World::at(int i)
{
    return _maps.at(i);
}


GameObject *World::player() const
{
    return _player;
}

void World::setPlayer(GameObject *player)
{
    _player = player;
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
