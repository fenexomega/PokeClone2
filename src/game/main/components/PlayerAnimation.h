#ifndef PLAYERANIMATION_H
#define PLAYERANIMATION_H

#include "components/cGraphic.h"
#include "graphics/SpriteAnimation.h"

class PlayerAnimation : public cGraphic
{
private:
    float timeCounter;
    int DirectionFrame(iGameObject *obj);
    SpriteAnimation *_animation;
    Vector2D<int> _oldAcc;
    Vector2D<int> _pos;
public:
    PlayerAnimation(Vector2D<int> pos, SpriteAnimation *sptAnm, iComponentMediator *mediator);
    ~PlayerAnimation();

    // iComponent interface
    void receiveMessage(int msg);

    // cGraphic interface
    void Update(iGameObject *obj, float dt);
    void Render(iGameObject *obj);
};

#endif // PLAYERANIMATION_H
