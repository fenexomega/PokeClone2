#include "GameObject.h"

#include "components/cInput.h"
#include "components/cGraphic.h"
#include "components/cPhysics.h"


Map *GameObject::map() const
{
    return _map;
}

void GameObject::setMap(Map *map)
{
    _map = map;
}


cPhysics *GameObject::physics() const
{
    return _physics;
}

void GameObject::setPhysics(cPhysics *physics)
{
    _physics = physics;
}

cInput *GameObject::input() const
{
    return _input;
}

void GameObject::setInput(cInput *input)
{
    _input = input;
}

cGraphic *GameObject::graphic() const
{
    return _graphic;
}

void GameObject::setGraphic(cGraphic *graphic)
{
    _graphic = graphic;
}
GameObject::GameObject(Map *map)
    : _map(map)
{

}


void GameObject::setComponents(cInput *input,
                               cPhysics *physics,
                               cGraphic *graphic)
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
    _physics->Update(this,_map,dt);
    _graphic->Update(this,dt);
}

void GameObject::Render()
{
    _graphic->Render(this);

}
