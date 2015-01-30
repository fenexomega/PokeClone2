#include "PlayerPhysics.h"

#include "util/Logger.h"

#include "systems/sysPhysics.h"

PlayerPhysics::PlayerPhysics(int _velocity)
    : velocity(_velocity)
{
    hitBox = NULL;
}

PlayerPhysics::~PlayerPhysics()
{
    delete hitBox;
}



void PlayerPhysics::Update(iGameObject *obj, World *world, float dt)
{
    if(hitBox == NULL)
    {
        hitBox = new Rect(0,0,32,16);
        PRINT(*hitBox);
    }


    obj->pos += obj->acc*velocity;

    hitBox->x = obj->pos.x;
    hitBox->y = obj->pos.y + 16;

    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(*hitBox,i))
        {
            PRINT(i);
            PRINT(*hitBox);
            obj->pos -= obj->acc*velocity;
            return;
        }
    }
    world->pos = -obj->pos;



}


void PlayerPhysics::receiveMessage(int msg)
{
}
