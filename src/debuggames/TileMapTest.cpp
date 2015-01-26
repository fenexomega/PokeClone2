#include "TileMapTest.h"

#include "graphics/Window.h"

TileMapTest::TileMapTest()
{

}

TileMapTest::~TileMapTest()
{

}

void TileMapTest::Init()
{
//    Window win(960,960,"hue");
    tilemap = new Tilemap("Contents/tiledmap.json");
    sprite = new Sprite("Contents/shitlight.png",96,96);
}

void TileMapTest::Update(float dt)
{

}

void TileMapTest::Render()
{
    tilemap->Render(0,0);
    sprite->Render(96,96);
}

void TileMapTest::Dispose()
{
    delete tilemap;
    delete sprite;
}
