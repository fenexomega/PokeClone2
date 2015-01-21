#ifndef MOVABLE_H
#define MOVABLE_H

#include "math/Vector2D.h"

class cMovable
{
private:
    Vector2D<int> direction;
public:
    cMovable(float _x,float _y)
    {
        direction.set(_x,_y);
    }
    void setVec(float _x, float _y)
    {
        direction.set(_x,_y);
    }
};

#endif // MOVABLE_H
