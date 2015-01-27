#include "GameObject.h"

GameObject::GameObject(cInput *input, cPhysics *physics, cGraphic *graphic, World *world)
    : _input(input),_physics(physics),_graphic(graphic), _world(world)
{

}

GameObject::~GameObject()
{

}

void GameObject::Update(float dt)
{
    _input->Update(this);
//    _physics->Update(this,_world);
    _graphic->Update(this,dt);
}

void GameObject::Render()
{
    _graphic->Render(this);
}

