#ifndef TRAPPHYSICS_H
#define TRAPPHYSICS_H

#include "components/cPhysics.h"

class TrapPhysics : public cPhysics
{
public:
    TrapPhysics();
    ~TrapPhysics();

    // iComponent interface
public:
    void receiveMessage(int msg);

    // cPhysics interface
    void Update(iGameObject *obj, Map *world, float dt);
};

#endif // TRAPPHYSICS_H
