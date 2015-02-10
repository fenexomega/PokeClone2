#ifndef MAINGAME_H
#define MAINGAME_H

#include "interfaces/iGame.h"
class iGameObject;

class MainGame : public iGame
{
private:
    iGame *game;
    iGameObject *player;
    iGameObject *actualWorld;
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
