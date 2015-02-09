#ifndef MAINGAME_H
#define MAINGAME_H

#include "interfaces/iGame.h"
#include "graphics/Tilemap.h"
#include "interfaces/iGameObject.h"
#include "game/main/objects/World.h"

class MainGame : public iGame
{
private:
    iGame *game;
    iGameObject *player;
    iGameObject *enemy,*enemy2,*object;
    World *actualWorld;
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
