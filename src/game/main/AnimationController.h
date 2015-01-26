#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H

#include "graphics/SpriteAnimation.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"

class AnimationController
{
private:
    float timeCounter;
    int DirectionFrame(iGameObject *obj);
    Vector2D<int> oldAcc;
public:
    AnimationController();
    void Update(iGameObject *obj, SpriteAnimation *anm, float dt);
    ~AnimationController();
};

#endif // ANIMATIONCONTROLLER_H
