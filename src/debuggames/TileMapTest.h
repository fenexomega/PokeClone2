#ifndef TILEMAPTEST_H
#define TILEMAPTEST_H

#include "interfaces/iGame.h"
#include "TileMapTest/Tilemap.h"

class TileMapTest : public iGame
{
private:
    Tilemap *tilemap;
public:
    TileMapTest();
    ~TileMapTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void Draw();
    void Dispose();
};

#endif // TILEMAPTEST_H
