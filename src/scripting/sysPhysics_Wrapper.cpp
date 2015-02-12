#include "sysPhysics_Wrapper.h"

#include "physics/Rect.h"
#include "systems/sysPhysics.h"

Rect sysPhysics_Wrapper::toRect(lua::Value value)
{
    return Rect(value["x"],value["y"],value["w"],value["h"]);
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





sysPhysics_Wrapper::~sysPhysics_Wrapper()
{

}

