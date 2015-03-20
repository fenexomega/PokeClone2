#include "sysPhysics_Wrapper.h"

#include "physics/Rect.h"
#include "physics/Circle.h"
#include "systems/sysPhysics.h"

#include "luastate/LuaState.h"


#include "util/Logger.h"

Rect sysPhysics_Wrapper::toRect(lua::Value value)
{
    return Rect(value["x"],value["y"],value["w"],value["h"]);
}

Circle sysPhysics_Wrapper::toCircle(lua::Value value)
{
    return Circle(Vector2D(value["center"]["x"],
            value["center"]["y"]),value["radius"]);
}

Vector2D sysPhysics_Wrapper::toVector2D(lua::Value value)
{
    return Vector2D(value["x"],value["y"]);
}



sysPhysics_Wrapper::sysPhysics_Wrapper()
{

}

bool sysPhysics_Wrapper::onScreen(lua::Value value)
{

    Rect rect = toRect(value);
    return sysPhysics::onScreen(rect);
}

bool sysPhysics_Wrapper::onBorders(lua::Value value)
{
    return sysPhysics::onBorders(toRect(value));
}

bool sysPhysics_Wrapper::isCollidingRR(lua::Value obj1, lua::Value obj2)
{
    Rect rect1 = toRect(obj1);
    Rect rect2 = toRect(obj2);
    return sysPhysics::isColliding(rect1,rect2);
}

bool sysPhysics_Wrapper::isCollidingRC(lua::Value rect,lua::Value circle)
{
    Circle c = toCircle(circle);
    Rect r = toRect(rect);


    return sysPhysics::isColliding(r,c);
}

bool sysPhysics_Wrapper::isCollidingCP(lua::Value circle, lua::Value point)
{
    //TODO
    return true;
}





sysPhysics_Wrapper::~sysPhysics_Wrapper()
{

}

