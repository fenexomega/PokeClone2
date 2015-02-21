#include "TeleporterPhysics.h"

TeleporterPhysics::TeleporterPhysics(iComponentMediator *mediator)
    : cPhysics(mediator)
{

}

TeleporterPhysics::~TeleporterPhysics()
{

}



void TeleporterPhysics::receiveMessage(int msg)
{
    switch(msg)
    {
    case PLAYERNEAR:
        //TELEPORT CODE
        break;
    }
}

void TeleporterPhysics::Update(iGameObject *obj, World *world, float dt)
{
}
