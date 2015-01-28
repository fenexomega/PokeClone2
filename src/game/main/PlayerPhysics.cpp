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
        int h = aux.h/2;
        hitBox = new Rect(aux.x,aux.y + h,aux.w,h);

    }
    auto aux = obj->pos + ((world->layerSize/2) * obj->acc);
    aux.x += obj->rect.w;
    aux.y += obj->rect.h;
    PRINT(obj->pos);
//    if( world->atPos("colidiveis",aux.x,aux.y) == 0)
    {
        obj->pos += obj->acc*velocity;
        world->pos = -(obj->pos + obj->rect.w/2);

//        static Vector2D<int> vec = world->layerSize;
//        static Rect levelHitBox((aux.x/vec.x) * vec.x,
//                                (aux.y/vec.y) * vec.y,
//                                vec.x,vec.y);

//        if(sysPhysics::isColliding(*hitBox,levelHitBox))
//            return;

    }



}


void PlayerPhysics::receiveMessage(int msg)
{
}
