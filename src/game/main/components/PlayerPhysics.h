#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "game/components/cPhysics.h"
#include "components/MessageSender.h"
#include "physics/Rect.h"



#define MOVE_BACK  3


class PlayerPhysics : public cPhysics
{
private:
    iGameObject *_obj;
    World *_world;
    Rect _hitBox;
    int _velocity = 2;
    void Move(Vector2D<int> v);
public:
    PlayerPhysics(int velocity,Rect hitBox,
                  iComponentMediator *mediator);
    ~PlayerPhysics();

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);

    // Component interface
    void receiveMessage(int msg);

};

#endif // PLAYERPHYSICS_H
