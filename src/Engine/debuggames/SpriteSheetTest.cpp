#include "SpriteSheetTest.h"

#include "graphics/Drawer.h"

SpriteSheetTest::SpriteSheetTest()
{

}

SpriteSheetTest::~SpriteSheetTest()
{

}


void SpriteSheetTest::Init()
{
    spst = new SpriteSheet("Contents/test_tiles.png",32,32);
    anm = new SpriteAnimation("Contents/test_tiles.png",8,32,32);
    time = 0.0f;
}

void SpriteSheetTest::Update(float dt)
{
    time += dt;
    if(time >= 0.4f)
    {
        anm->UpdateAnimation();
        time = 0;
    }
}

void SpriteSheetTest::Render()
{
    for (int i = 0; i < 16; ++i)
    {
        spst->Render(i*32,0,i);
    }
    anm->Render(0,32);
}

void SpriteSheetTest::Dispose()
{
    delete anm;
    delete spst;
}


void SpriteSheetTest::SendMessage(MSG msg)
{
}
