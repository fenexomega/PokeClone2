#include "PlayerPhysics.h"

#include "util/Logger.h"

#include "systems/sysPhysics.h"

//TODO hitbox finetuning

PlayerPhysics::PlayerPhysics(int velocity, Rect hitBox, iComponentMediator *mediator)
    : _hitBox(hitBox),_velocity(velocity),cPhysics(mediator)
{
    _offset = _hitBox.w/4;
    _hitBox.w -= _offset;
}

PlayerPhysics::~PlayerPhysics()
{

}

void PlayerPhysics::Move(Vector2D<int> v)
{
    _obj->pos += v;

    //TODO melhorar isso
    //o vetor POS dá a posição exata no MEIO
    _hitBox.x = _obj->pos.x - (_hitBox.w + _offset)/2 + _offset/2;
    _hitBox.y = _obj->pos.y;

    /*BUG quando o player e o inimigo se mechem na
     * diagonal, o vetor resultante é 2* maior que
     * deveria ser.
     * Isso acontece porque o objeto se move
     * ao mesmo tempo em x e y, movendo assim
     * duas unidades!
     */

    //TODO O Mundo deveria se mexer de forma independente?
    _world->pos = -_obj->pos;

}


void PlayerPhysics::Update(iGameObject *obj, Map *world, float dt)
{

    _obj = obj;
    _world = world;
    Move(obj->acc*_velocity);

    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i))
        {
            Move(-_obj->acc*_velocity);
            return;
        }
    }
}


void PlayerPhysics::receiveMessage(int msg)
{

    if(msg == MOVE_BACK)
    {
        //Observer Notify?
        Move(-_obj->acc*_velocity);
    }
}

