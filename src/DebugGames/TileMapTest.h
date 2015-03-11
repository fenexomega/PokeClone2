#ifndef TILEMAPTEST_H
#define TILEMAPTEST_H

#include "interfaces/iGame.h"
#include "graphics/Tilemap.h"
#include "graphics/Sprite.h"

class TileMapTest : public iGame
{
private:
    Tilemap *tilemap;
    Sprite *sprite;
public:
    TileMapTest();
    ~TileMapTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();
};

#endif // TILEMAPTEST_H
