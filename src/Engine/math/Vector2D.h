#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <iostream>

#define ABS(X) (X) > 0 ? (X) : -(X)


class Vector2D
{
public:
    float x, y;

    Vector2D() : x(0.0f), y(0.0f) {}
    Vector2D(float _x, float _y) : x(_x), y(_y) {}

    inline Vector2D operator +(Vector2D v)
    {
        return Vector2D (x + v.x, y + v.y);
    }

    inline Vector2D operator -(Vector2D v)
    {
        return Vector2D (x - v.x, y - v.y);
    }

    inline Vector2D operator *(float i)
    {
        Vector2D aux = *this;
        aux.x *= i;
        aux.y *= i;
        return aux;
    }

    inline Vector2D operator /(float i)
    {
        Vector2D aux = *this;
        aux.x /= i;
        aux.y /= i;
        return aux;
    }

    inline Vector2D operator +(float i)
    {
        Vector2D aux = *this;
        aux.x += i;
        aux.y += i;
        return aux;
    }

    inline Vector2D operator -(float i)
    {
        Vector2D aux = *this;
        aux.x -= i;
        aux.y -= i;
        return aux;
    }

    inline Vector2D operator +=(Vector2D v)
    {
        x = x + v.x;
        y = y + v.y;
        return *this;
    }

    inline Vector2D operator -=(Vector2D v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    inline Vector2D operator=(Vector2D v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    inline bool operator ==(Vector2D v)
    {
        return x == v.x && y == v.y ? true : false;
    }

    inline bool operator !=(Vector2D v)
    {
        return x == v.x && y == v.y ? false : true;
    }

    inline Vector2D operator+=(double i)
    {
        x += i;
        y += i;
        return *this;
    }

    inline Vector2D operator-=(double i)
    {
        x -= i;
        y -= i;
        return *this;
    }

    inline double size()
    {
        return sqrt(x*x + y*y);
    }

    inline Vector2D set(float _x, float _y)
    {
        x = _x;
        y = _y;
        return *this;
    }

    inline bool isZero()
    {
        auto res = ABS(x - y);
        return res <= 0.01;
    }

    inline Vector2D floor()
    {
        Vector2D aux;
        aux.x = (int) this->x;
        aux.y = (int) this->y;
        return aux;
    }

    inline Vector2D ceiling()
    {
        Vector2D aux;
        aux.x = int(this->x) < this->x ? (int) x+1 : (int) x;
        aux.y = int(this->y) < this->y ? (int) y+1 : (int) y;
    }
};

inline std::ostream& operator<<(std::ostream& ost,Vector2D vec)
{
    return ost << "{ " << vec.x << ", " << vec.y << " }";
}

inline Vector2D operator-(Vector2D v)
{
    v.x *= -1;
    v.y *= -1;
    return v;
}



#endif // VECTOR2D_H
