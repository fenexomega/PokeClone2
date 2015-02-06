#include "AnimationController.h"

#include "graphics/Drawer.h"

#include "util/Logger.h"

int AnimationController::DirectionFrame(iGameObject *obj)
{

    int result;
    if(obj->acc.y == -1)
        result = _animation->amtOfFrames*3;
    else if(obj->acc.y ==  1)
        result = 0;
    else if(obj->acc.x ==  1)
        result = _animation->amtOfFrames;
    else if( obj->acc.x == -1)
        result = _animation->amtOfFrames*2;
    return result;
}

AnimationController::AnimationController(SpriteAnimation *sptAnm, iComponentMediator *mediator)
    : _animation(sptAnm),MessageSender(mediator)
{
    timeCounter = 0;
}


AnimationController::~AnimationController()
{
    delete _animation;
}



void AnimationController::receiveMessage(int msg)
{
}

void AnimationController::Update(iGameObject *obj, float dt)
{
    timeCounter += dt;
    if(timeCounter >= 0.25f)
    {
        _animation->UpdateAnimation();
        timeCounter = 0;
    }

    if(obj->acc.x == 0 && obj->acc.y == 0)
    {
        _animation->setKeyFrame(_animation->getKeyFrame());
    }
    else
        if(oldAcc != obj->acc)
            _animation->setKeyFrame(DirectionFrame(obj));
    oldAcc = obj->acc;
}

void AnimationController::Render(iGameObject *obj)
{
    _animation->Render(obj->rect.x,obj->rect.y);

}

