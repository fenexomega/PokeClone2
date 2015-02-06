#ifndef ENEMYPHYSICS_H
#define ENEMYPHYSICS_H

#include "game/components/cPhysics.h"

class EnemyPhysics : public cPhysics
{
private:
    int _velocity = 2;
    Rect _hitBox;
public:
    EnemyPhysics(int velocity, Rect hitBox);
    ~EnemyPhysics();

    // iComponent interface
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, World *world, float dt);


};

#endif // ENEMYPHYSICS_H
