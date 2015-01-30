#ifndef SYSPHYSICS_H
#define SYSPHYSICS_H

#include "interfaces/iGameObject.h"

static const  char NO_COL = 0;
static const  char X_AXIS_COL = 1;
static const  char Y_AXIS_COL = 2;

class sysPhysics
{
public:
    static bool isColliding(Rect obj1, Rect obj2);
    static int onBorders(Rect obj);
};

#endif // SYSPHYSICS_H
