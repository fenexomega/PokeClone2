#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "physics/Circle.h"
#include "physics/Rect.h"
#include "systems/sysPhysics.h"
#include "math/Vector2D.h"

Circle c1(Vector2D<int>(0,0),5);
Circle c2(Vector2D<int>(2,0),5);
Circle c3(Vector2D<int>(7,7),1);
Circle c4(2,2,2);
Vector2D<int> p1(3,0);
Vector2D<int> p2(0,4);
Rect r1(0,0,5,5);
Rect r2(6,6,2,2);
Rect r3(15,2,4,4);
Rect r4(2,15,4,4);



TEST_CASE("Teste da colisão dos circulos","[Circle]")
{


    REQUIRE(sysPhysics::DistanceOf(p1,p2) == 5.0f);

    //Devem colidir
    REQUIRE(sysPhysics::isColliding(c1,c2));
    REQUIRE(sysPhysics::isColliding(c1,p2));

    //Não devem colidir
    REQUIRE_FALSE(sysPhysics::isColliding(r2,c1));
    REQUIRE_FALSE(sysPhysics::isColliding(r1,r2));
    REQUIRE_FALSE(sysPhysics::isColliding(c3,p1));
    REQUIRE_FALSE(sysPhysics::isColliding(c1,c3));
    REQUIRE_FALSE(sysPhysics::isColliding(r3,c4));
    REQUIRE_FALSE(sysPhysics::isColliding(r4,c4));

}

TEST_CASE("Colisão Quadrado-Circulo","[Rect-Circle]")
{
    REQUIRE(sysPhysics::isColliding(r1,c1));
    REQUIRE(sysPhysics::isColliding(r1,c2));
}
