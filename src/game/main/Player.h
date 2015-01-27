#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "game/objects/GameObject.h"
#include "physics/Rect.h"
#include "graphics/SpriteAnimation.h"
#include "math/Vector2D.h"
#include "game/components/cInput.h"
#include "game/main/AnimationController.h"

class Player //: public GameObject
{
private:
    SpriteAnimation *anm;
    AnimationController animation;
    cInput *input;
public:
    Player(std::string fileName, Vector2D<int> worldPos,
           Rect _rect, int frameAmt, cInput *_inputComponent , int keyFrame = 0);
    ~Player();
    // GameObject interface
    void Update(float dt);
    void Render();
};

#endif // PLAYER_H
