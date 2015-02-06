#include "ObjectInput.h"

ObjectInput::ObjectInput(iComponentMediator *mediator)
    : MessageSender(mediator)
{

}

ObjectInput::~ObjectInput()
{

}



void ObjectInput::receiveMessage(int msg)
{
    if(msg == PLAYER_COLLIDING)
        isAble = true;
}

void ObjectInput::Update(iGameObject *player, float dt)
{

    isAble = false;
}
