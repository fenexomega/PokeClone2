#ifndef SYSPHYSICS_H
#define SYSPHYSICS_H

#include "interfaces/iGameObject.h"

class sysPhysics
{
public:
    static bool isColliding(Rect obj1, Rect obj2);
};

#endif // SYSPHYSICS_H
