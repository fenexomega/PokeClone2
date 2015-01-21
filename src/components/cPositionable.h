#ifndef POSITIONABLE_H
#define POSITIONABLE_H

#include "math/Vector2D.h"

class cPositionable
{
public:
    Vector2D<int> pos;
    cPositionable(int x, int y)
    {
        pos.set(x,y);
    }

    cPositionable()
    {
        pos.set(0,0);
    }
};

#endif // POSITIONABLE_H
