#include "World.h"

#include "game/main/objects/Map.h"

Map *World::world() const
{
    return _world;
}

void World::setWorld(Map *world)
{
    _world = world;
}
World::World()
{

}

World::~World()
{
    delete _world;
}



void World::Update(float dt)
{
    _world->Update(dt);
}

void World::Render()
{
    _world->Render();
}
