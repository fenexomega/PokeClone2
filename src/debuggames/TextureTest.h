#ifndef TEXTURETEST_H
#define TEXTURETEST_H

#include "interfaces/iGame.h"
#include "Objects/RenderMe.h"

extern char* SCREEN_NAME;

class TextureTest : public iGame
{
private:
    RenderMe *renderOBJ;
public:
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();

};

#endif // TEXTURETEST_H
