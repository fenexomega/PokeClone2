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
        Rect aux = obj->rect;
        int h = 16;//aux.h/2;
        hitBox = new Rect(0,0,32,32);
        PRINT(*hitBox);
        PRINT(obj->rect);

    }
    //TODO a largura e altura do game object estão nulas!
    // não consigo pensar em como passar por parametro
    hitBox->x = obj->pos.x;
    hitBox->y = obj->pos.y;

    Vector2D<int> auxVec = (obj->pos + 16) + obj->acc * 16;
    auxVec.x /= world->tileSize.x;
    auxVec.y /= world->tileSize.y;
    auxVec += obj->acc;
//    PRINT(world->atPos("colidiveis",auxVec.x,auxVec.y));
    if(world->atPos("colidiveis",auxVec.x,auxVec.y) != 0)
    {
        Rect tileBox = world->atPosRect(auxVec.x,auxVec.y);
        PRINT(tileBox);
        PRINT(*hitBox);
        if(sysPhysics::isColliding(*hitBox,tileBox))
            return;
    }
    obj->pos += obj->acc*velocity;
    world->pos = -obj->pos;


}


void PlayerPhysics::receiveMessage(int msg)
{
}
