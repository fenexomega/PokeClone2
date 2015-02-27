#ifndef MAINGAME_H
#define MAINGAME_H

#include "interfaces/iGame.h"
class iGameObject;

class World;


class MainGame : public iGame
{
private:
    iGame *game;
    World *_world;
public:
    MainGame(iGame *_game);
    ~MainGame();

    // iGame interface
    void Init();
    void Update(float dt);
    void SendMessage(MSG msg, void* content);
    void Render();
    void Dispose();
};

#endif // MAINGAME_H
