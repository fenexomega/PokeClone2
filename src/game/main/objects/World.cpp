#include "World.h"

#include "main/objects/Map.h"
#include "main/objects/GameObject.h"

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
    _outerMap = map;
    _mapHasChanged = true;
}

void World::setActualMap(std::string mapName, Vector2D playerPos)
{
    _outerMap = findMapByName(mapName);
    _outerMap->pos = -playerPos;
    GameObject *player = dynamic_cast<GameObject*>(_outerMap->player);
    player->pos = playerPos;
    player->setMap(_outerMap);
    _mapHasChanged = true;


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
    if(_mapHasChanged)
    {
        _actualMap = _outerMap;
        _mapHasChanged = false;
    }
    _actualMap->Update(dt);
}

void World::Render()
{
    //Ugly hack, but...
    if(_actualMap)
        _actualMap->Render();
}
