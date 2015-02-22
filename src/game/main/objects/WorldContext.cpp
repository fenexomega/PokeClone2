#include "WorldContext.h"

#include "game/main/objects/World.h"

World *WorldContext::world() const
{
    return _world;
}

void WorldContext::setWorld(World *world)
{
    _world = world;
}
WorldContext::WorldContext()
{

}

WorldContext::~WorldContext()
{
    delete _world;
}



void WorldContext::Update(float dt)
{
    _world->Update(dt);
}

void WorldContext::Render()
{
    _world->Render();
}
