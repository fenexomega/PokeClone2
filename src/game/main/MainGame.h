#ifndef MAINGAME_H
#define MAINGAME_H

#include "interfaces/iGame.h"
#include "graphics/Tilemap.h"
#include "game/main/Player.h"
#include "game/objects/GameObject.h"

class MainGame : public iGame
{
private:
    iGame *game;
    GameObject *player;
    Tilemap *map;

public:
    MainGame(iGame *_game);
    ~MainGame();

    // iGame interface
    void Init();
    void Update(float dt);
    void SendMessage(MSG msg);
    void Render();
    void Dispose();
};

#endif // MAINGAME_H
