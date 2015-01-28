#include "GameObject.h"

GameObject::GameObject(cInput *input, cPhysics *physics, cGraphic *graphic, World *world)
    : _input(input),_physics(physics),_graphic(graphic), _world(world)
{
    mediator.addComponent(input);
    mediator.addComponent(physics);
    mediator.addComponent(graphic);

}

GameObject::~GameObject()
{

}

void GameObject::Update(float dt)
{
    _input->Update(this);
    _physics->Update(this,_world,dt);
    _graphic->Update(this,dt);
}

void GameObject::Render()
{
    _graphic->Render(this);
}

