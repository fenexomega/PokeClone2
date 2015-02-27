#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "physics/Circle.h"
#include "physics/Rect.h"
#include "systems/sysPhysics.h"
#include "math/Vector2D.h"

TEST_CASE("Teste da colisão dos circulos","[Circle]")
{
    Circle c1(Vector2D<int>(0,0),5);
    Circle c2(Vector2D<int>(2,0),5);
    Circle c3(Vector2D<int>(7,7),1);
    Vector2D<int> point1(3,0);
    Vector2D<int> point2(0,4);
    Rect rect1(0,0,5,5);
    Rect rect2(6,6,2,2);


    REQUIRE(sysPhysics::DistanceOf(point1,point2) == 5.0f);
    //Devem colidir
    REQUIRE(sysPhysics::isColliding(c1,c2));
    REQUIRE(sysPhysics::isColliding(c1,point2));

    //Não devem colidir
    REQUIRE_FALSE(sysPhysics::isColliding(rect2,c1));
    REQUIRE_FALSE(sysPhysics::isColliding(rect1,rect2));
    REQUIRE_FALSE(sysPhysics::isColliding(c3,point1));
    REQUIRE_FALSE(sysPhysics::isColliding(c1,c3));
}
