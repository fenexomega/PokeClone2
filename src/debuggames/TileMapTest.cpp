#include "TileMapTest.h"

TileMapTest::TileMapTest()
{

}

TileMapTest::~TileMapTest()
{

}



void TileMapTest::Init()
{
    tilemap = new Tilemap("Contents/tiledmap.json");
}

void TileMapTest::Update(float dt)
{
}

void TileMapTest::Draw()
{
    tilemap->Draw();
}

void TileMapTest::Dispose()
{
    delete tilemap;
}
