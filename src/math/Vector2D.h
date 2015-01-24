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

    inline Vector2D operator +(Vector2D v)
    {
        return Vector2D<TYPE> (x + v.x, y + v.y);
    }

    inline Vector2D operator -(Vector2D v)
    {
        return Vector2D<TYPE> (x - v.x, y - v.y);
    }

    inline Vector2D& operator +=(Vector2D v)
    {
        x = x + v.x;
        y = y + v.y;
        return *this;
    }

    inline Vector2D& operator -=(Vector2D v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    inline bool operator ==(Vector2D v)
    {
        return x == v.getX() && v.getY() ? true : false;
    }

    inline Vector2D& operator+=(TYPE i)
    {
        x += i;
        y += i;
        return *this;
    }

    inline Vector2D& operator-=(TYPE i)
    {
        x -= i;
        y -= i;
        return *this;
    }

    inline double size()
    {
        return sqrt(x*x + y*y);
    }

    inline Vector2D* set(TYPE _x, TYPE _y)
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
