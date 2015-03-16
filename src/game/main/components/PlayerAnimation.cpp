#include "PlayerAnimation.h"

PlayerAnimation::PlayerAnimation(Vector2D pos,SpriteAnimation *sptAnm,iComponentMediator *mediator)
   : _animation(sptAnm),cGraphic(mediator),_pos(pos)
{
    timeCounter = 0;

}

PlayerAnimation::~PlayerAnimation()
{
    delete _animation;
}


int PlayerAnimation::DirectionFrame(iGameObject *obj)
{

    int result;
    if(obj->acc.y <= -1)
        result = _animation->amtOfFrames()*3;
    else if(obj->acc.y >=  1)
        result = 0;
    else if(obj->acc.x >=  1)
        result = _animation->amtOfFrames();
    else if( obj->acc.x <= -1)
        result = _animation->amtOfFrames()*2;
    return result;
}

void PlayerAnimation::receiveMessage(int msg)
{
}

void PlayerAnimation::Update(iGameObject *obj, float dt)
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
        if(_oldAcc != obj->acc)
            _animation->setKeyFrame(DirectionFrame(obj));
    _oldAcc = obj->acc;
}

void PlayerAnimation::Render(iGameObject *obj)
{
    _animation->Render(_pos.x,_pos.y);
}
