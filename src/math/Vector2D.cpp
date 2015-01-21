#include "Vector2D.h"

template<class TYPE>
Vector2D<TYPE> Vector2D<TYPE> ::operator +(Vector2D<TYPE>  v)
{
    return Vector2D<TYPE> (x + v.x, y + v.y);
}

template<class TYPE>
Vector2D<TYPE>  Vector2D<TYPE> ::operator -(Vector2D<TYPE>  v)
{
    return Vector2D<TYPE> (x - v.x, y - v.y);
}

template<class TYPE>
Vector2D<TYPE> & Vector2D<TYPE> ::operator +=(Vector2D<TYPE>  v)
{
    x = x + v.x;
    y = y + v.y;
    return *this;
}

template<class TYPE>
bool Vector2D<TYPE> ::operator ==(Vector2D<TYPE>  v)
{
    return x == v.getX() && v.getY() ? true : false;
}

template<class TYPE>
TYPE Vector2D<TYPE> ::size()
{
    return sqrt(x*x + y*y);
}

