#include "AnimationController.h"

int AnimationController::DirectionFrame(iGameObject *obj)
{
    int result;
    if(obj->acc.y == -1)
        result = 12;
    else if(obj->acc.y ==  1)
        result = 0;
    else if(obj->acc.x ==  1)
        result = 4;
    else if( obj->acc.x == -1)
        result = 8;
    return result;
}

AnimationController::AnimationController()
{
    timeCounter = 0;
}


void AnimationController::Update(iGameObject *obj, SpriteAnimation *anm,float dt)
{
    timeCounter += dt;

    if(timeCounter >= 0.3f)
    {
        anm->UpdateAnimation();
        timeCounter = 0;
    }

    if(obj->acc.x == 0 && obj->acc.y == 0)
    {
        anm->setKeyFrame(anm->getKeyFrame());
    }
    else
        if(oldAcc != obj->acc)
            anm->setKeyFrame(DirectionFrame(obj));
    oldAcc = obj->acc;

}

AnimationController::~AnimationController()
{

}

