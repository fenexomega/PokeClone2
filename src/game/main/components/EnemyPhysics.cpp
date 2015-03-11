#include "EnemyPhysics.h"

#include "systems/sysPhysics.h"

#include "util/Logger.h"

#include "main/objects/Door.h"

EnemyPhysics::EnemyPhysics(int velocity, Rect hitBox,iGameObject *player, iComponentMediator *mediator)
    : _velocity(velocity),_hitBox(hitBox),cPhysics(mediator),_player(player)

{
    _offset = _hitBox.w/4;
    _hitBox.w -= _offset;
}


void EnemyPhysics::Move(Vector2D<int> v)
{
    _obj->pos += v;
    _obj->rect.x = _world->pos.x + _obj->pos.x + _world->offset.x;
    _obj->rect.y = _world->pos.y + _obj->pos.y + _world->offset.y;
    _hitBox.x = _obj->pos.x + _offset/2;
    _hitBox.y = _obj->pos.y;

}

EnemyPhysics::~EnemyPhysics()
{

}



void EnemyPhysics::receiveMessage(int msg)
{

}

void EnemyPhysics::Update(iGameObject *obj, Map *world, float dt)
{
    _obj = obj;
    _world = world;
    Move(obj->acc*_velocity);


    std::vector<Rect> colidables = world->getLayersRect("colidiveis");
    //Ver se está colidindo com algum gameObject
    bool colliding = false;
    for(iGameObject *i : world->gameObjects)
        if(sysPhysics::isColliding(obj->rect,i->rect))
        {

            //Se for uma porta, você deve colidir
            // senão, pode passar.
            if(i->type == "door")
            {
                //verifica se a porta está trancada
                if( !((Door *) i)->_open )
                    colliding = true;
            }

            break;
        }


    //BUG Colisão com os inimigos
    for(iGameObject *i : world->gameEnemies)
        if(sysPhysics::isColliding(obj->rect,i->rect))
        {
            //BUG estão colidindo mas não saem do canto
            colliding = true;
            break;
        }



    //Colisão com o mundo
    for(auto i : colidables)
    {
        if(sysPhysics::isColliding(_hitBox,i)
                || colliding)
        {
            Move(-obj->acc*_velocity);

            break;
        }
    }

}

