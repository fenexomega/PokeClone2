#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H

#include "graphics/SpriteAnimation.h"
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
    AnimationController(SpriteAnimation *sptAnm,iComponentMediator *mediator);
    ~AnimationController();

    // Component interface
    void receiveMessage(int msg);
    // cGraphic interface
    void Update(iGameObject *obj, float dt);
    void Render(iGameObject *obj);


};

#endif // ANIMATIONCONTROLLER_H
