#include "EnemyObject.h"

EnemyObject::EnemyObject(cInput *input, cPhysics *physics, cGraphic *graphic, World *world)
    : _input(input),_physics(physics),_graphic(graphic), _world(world)
{
    _mediator.addComponent(input);
    _mediator.addComponent(physics);
    _mediator.addComponent(graphic);
}

EnemyObject::~EnemyObject()
{
    delete _input;
    delete _physics;
    delete _graphic;
}

void EnemyObject::Update(float dt)
{
    _input->Update(this,dt);
    _physics->Update(this,_world,dt);
    _graphic->Update(this,dt);
}

void EnemyObject::Render()
{
    _graphic->Render(this);

}
