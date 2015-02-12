#ifndef ENEMYPHYSICS_H
#define ENEMYPHYSICS_H

#include "game/components/cPhysics.h"

class EnemyPhysics : public cPhysics
{
private:
    int _velocity = 2;
    Rect _hitBox;
    iGameObject *_player;
    iGameObject *_obj;
    World *_world;
    void Move(Vector2D<int> v);
public:
    EnemyPhysics(int velocity, Rect hitBox,iGameObject *player, iComponentMediator *mediator);
    ~EnemyPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);


};

#endif // ENEMYPHYSICS_H
