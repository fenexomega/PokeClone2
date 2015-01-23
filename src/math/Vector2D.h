#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <iostream>

template <class TYPE>
class Vector2D
{
public:
    TYPE x, y;

    Vector2D() : x(0.0f), y(0.0f) {}
    Vector2D(TYPE _x, TYPE _y) : x(_x), y(_y) {}

    Vector2D operator +(Vector2D v);
    Vector2D operator -(Vector2D v);
    Vector2D& operator +=(Vector2D v);
    bool operator    ==(Vector2D v);

    TYPE size();

    Vector2D* set(TYPE _x, TYPE _y)
    {
        x = _x;
        y = _y;
        return this;
    }

};

template <class TYPE>
std::ostream& operator<<(std::ostream& ost,Vector2D<TYPE> vec)
{
    return ost << "{ " << vec.x << ", " << vec.y << " }";
}

#endif // VECTOR2D_H
