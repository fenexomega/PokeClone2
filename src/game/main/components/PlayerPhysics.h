#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "game/components/cPhysics.h"
#include "physics/Rect.h"

class PlayerPhysics : public cPhysics
{
private:
    iGameObject *_obj;
    Map *_world;
    Rect _hitBox;
    int _velocity = 2;
    int _offset;
    void Move(Vector2D<int> v);
public:
    PlayerPhysics(int velocity,Rect hitBox,
                  iComponentMediator *mediator);
    ~PlayerPhysics();

    // cPhysics interface
    void Update(iGameObject *obj, Map *world, float dt);

    // Component interface
    void receiveMessage(int msg);

};

#endif // PLAYERPHYSICS_H
