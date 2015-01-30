#include "sysPhysics.h"

#include "graphics/Window.h"

bool sysPhysics::isOverlapping(int minA, int maxA,int minB, int maxB)
{
    return minB <= maxA && minA <= maxB;
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

int sysPhysics::onBorders(Rect obj)
{

    if(obj.x + obj.w >= Window::getWidth() || obj.x <= 0)
        return X_AXIS_COL;
    if(obj.y + obj.h >= Window::getHeight() || obj.y <= 0)
        return Y_AXIS_COL;
    return NO_COL;

}
