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
}

void TileMapTest::Update(float dt)
{
    tilemap->Update(dt);
}

void TileMapTest::Draw()
{
    tilemap->Draw();
}

void TileMapTest::Dispose()
{
    delete tilemap;
}
