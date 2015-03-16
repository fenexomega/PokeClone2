#ifndef SYSPHYSICS_WRAPPER_H
#define SYSPHYSICS_WRAPPER_H

namespace lua
{
    class Value;
}

#include "math/Vector2D.h"

class Rect;
class Circle;

class sysPhysics_Wrapper
{
protected:
    static Rect toRect(lua::Value value);
    static Circle toCircle(lua::Value value);
    static Vector2D toVector2D(lua::Value value);
public:
    sysPhysics_Wrapper();
    static bool onScreen(lua::Value value);
    static bool onBorders(lua::Value value);
    static bool isCollidingRR(lua::Value obj1, lua::Value obj2);
    static bool isCollidingRC(lua::Value rect,lua::Value circle);
    static bool isCollidingCP(lua::Value circle, lua::Value point);


    ~sysPhysics_Wrapper();
};

#endif // SYSPHYSICS_WRAPPER_H
