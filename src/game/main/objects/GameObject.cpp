#include "GameObject.h"

#include "game/components/cInput.h"
#include "game/components/cGraphic.h"
#include "game/components/cPhysics.h"

GameObject::GameObject(Map *world)
    : _world(world)
{

}

void GameObject::setComponents(cInput *input, cPhysics *physics, cGraphic *graphic)
{
    _input = input;
    _physics = physics;
    _graphic = graphic;

}

GameObject::~GameObject()
{
    delete _input;
    delete _physics;
    delete _graphic;
}

void GameObject::Update(float dt)
{
    _input->Update(this,dt);
    _physics->Update(this,_world,dt);
    _graphic->Update(this,dt);
}

void GameObject::Render()
{
    _graphic->Render(this);

}
