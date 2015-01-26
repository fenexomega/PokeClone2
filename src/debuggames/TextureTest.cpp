#include "TextureTest.h"

void TextureTest::Init()
{
    renderOBJ = new RenderMe("Contents/Debug/texture.png");
    //sysGraphics::setWindowResolution(1366,768);
}

void TextureTest::Update(float dt)
{
    for (int var = 0; var < 4; ++var) {
        if(sysInput::isMouseButtonDown(var))
            uLOG("O botão " << var << " está pressionado.");
    }
}

void TextureTest::Render()
{
    renderOBJ->Render();
}

void TextureTest::Dispose()
{
    delete renderOBJ;
}
