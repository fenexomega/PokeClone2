#ifndef GAME_H
#define GAME_H

#include "interfaces/iGame.h"

class Game : public iGame
{
public:

    Game();
    void Init();
    void Update(float dt);
    void Draw();
    void Dispose();
};

#endif // GAME_H
