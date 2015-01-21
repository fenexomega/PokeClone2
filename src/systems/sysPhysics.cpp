#include "sysPhysics.h"

bool sysPhysics::isColliding(Rect obj1, Rect obj2)
{
    if(obj1 == obj2)
        return false;
    if(obj1.x + obj1.w >= obj2.x &&
       obj1.x  <= obj2.x + obj2.w)
        if(obj1.y + obj1.h >= obj2.y &&
           obj1.y + obj1.h <= obj2.y + obj2.h)
                    return true;
   return false;
}
