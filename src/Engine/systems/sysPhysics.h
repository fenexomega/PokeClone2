#ifndef SYSPHYSICS_H
#define SYSPHYSICS_H


#include "math/Vector2D.h"

static const  char NO_COL = 0;
static const  char X_AXIS_COL = 1;
static const  char Y_AXIS_COL = 2;

class Rect;
class Circle;

class sysPhysics
{
protected:
    static bool isOverlapping(int minA, int maxA, int minB, int maxB);
    static int clampOnRange(int min,int max, int v);
public:
    static bool isColliding(Rect obj1, Rect obj2);
    static bool isColliding(Vector2D<int> point, Rect rect);
    static bool isColliding(Rect rect, Circle circle);
    static bool isColliding(Circle circle,Vector2D<int> point);
    static bool isColliding(Circle c1,Circle c2);



    static float DistanceOf(Vector2D<int> p1, Vector2D<int> p2);

    static int onBorders(Rect obj);
    static bool onScreen(Rect obj);
};

#endif // SYSPHYSICS_H
