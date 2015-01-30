#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H

#include "graphics/SpriteAnimation.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"
#include "game/components/cGraphic.h"

class AnimationController : public cGraphic
{
private:
    float timeCounter;
    int DirectionFrame(iGameObject *obj);
    SpriteAnimation *_animation;
    Vector2D<int> oldAcc;
public:
    AnimationController(SpriteAnimation *sptAnm);
    ~AnimationController();

    // Component interface
    void receiveMessage(int msg);
    // cGraphic interface
    void Update(iGameObject *obj, float dt);
    void Render(iGameObject *obj);

    // cGraphic interface
    Vector2D<int> getWidthAndHeight();
};

#endif // ANIMATIONCONTROLLER_H
