#include "sysPhysics.h"

#include "graphics/Window.h"

#include "physics/Rect.h"
#include "physics/Circle.h"
#include <cmath>

bool sysPhysics::isOverlapping(int minA, int maxA,int minB, int maxB)
{
    return minB <= maxA && minA <= maxB;
}

int sysPhysics::clampOnRange(int min, int max, int v)
{
    if(v < min)
        return min;
    else if(v < max)
        return max;
    else
        return v;
}

bool sysPhysics::isColliding(Rect obj1, Rect obj2)
{
    if(obj1 == obj2)
        return false;
    if(obj1.x + obj1.w >= obj2.x &&
            obj1.x  <= obj2.x + obj2.w)
        if(obj1.y + obj1.h >= obj2.y &&
                obj1.y  <= obj2.y + obj2.h)
            return true;
    return false;

}

bool sysPhysics::isColliding(Vector2D<int> point, Rect rect)
{
    if(point.x >= rect.x &&
            point.x  <= rect.x + rect.w)
        if(point.y >= rect.y &&
                point.y <= rect.y + rect.h)
            return true;
    return false;
}

bool sysPhysics::isColliding(Rect rect, Circle circle)
{
    //Ponto do triangulo mais perto do circulo
    Vector2D<int> p;
    p.x = clampOnRange(rect.x,rect.x + rect.w, circle.center.x);
    p.y = clampOnRange(rect.y,rect.y + rect.h, circle.center.y);

    return isColliding(circle , p);
}

bool sysPhysics::isColliding(Circle circle, Vector2D<int> point)
{
    return DistanceOf(circle.center,point) <= circle.radius;
}

bool sysPhysics::isColliding(Circle c1, Circle c2)
{
    return DistanceOf(c1.center,c2.center) <= c1.radius + c2.radius;
}

float sysPhysics::DistanceOf(Vector2D<int> p1, Vector2D<int> p2)
{
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}

int sysPhysics::onBorders(Rect obj)
{

    if(obj.x + obj.w >= Window::getWidth() || obj.x <= 0)
        return X_AXIS_COL;
    if(obj.y + obj.h >= Window::getHeight() || obj.y <= 0)
        return Y_AXIS_COL;
    return NO_COL;

}

bool sysPhysics::onScreen(Rect obj)
{
    Rect win(0,0,Window::getWidth(),Window::getHeight());
    return isColliding(obj,win);
}

