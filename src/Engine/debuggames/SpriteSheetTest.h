#ifndef SPRITESHEETTEST_H
#define SPRITESHEETTEST_H

#include "interfaces/iGame.h"
#include "graphics/SpriteSheet.h"
#include "graphics/SpriteAnimation.h"

class SpriteSheetTest : public iGame
{
private:
    SpriteSheet *spst;
    SpriteAnimation *anm;
    float time;
public:
    SpriteSheetTest();
    ~SpriteSheetTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();

    // iGame interface
    void SendMessage(MSG msg);
};

#endif // SPRITESHEETTEST_H
