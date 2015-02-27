#ifndef CIRCLE
#define CIRCLE

#include "math/Vector2D.h"

class Circle
{
public:
    Circle(Vector2D<int> center,int Radius)
        : center(center),radius(Radius) {}

    Vector2D<int> center;
    int radius;
};

#endif // CIRCLE

