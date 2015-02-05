#include "PlayerObject.h"

PlayerObject::PlayerObject(cInput *input, cPhysics *physics, cGraphic *graphic, World *world)
    : _input(input),_physics(physics),_graphic(graphic), _world(world)
{
    _mediator.addComponent(input);
    _mediator.addComponent(physics);
    _mediator.addComponent(graphic);
}

PlayerObject::~PlayerObject()
{
    //TODO delete components?
    delete _input;
    delete _physics;
    delete _graphic;
}

void PlayerObject::Update(float dt)
{
    _input->Update(this,dt);
    _physics->Update(this,_world,dt);
    _graphic->Update(this,dt);
}

void PlayerObject::Render()
{
    _graphic->Render(this);
}
