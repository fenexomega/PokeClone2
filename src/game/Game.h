#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "interfaces/iGame.h"

using std::shared_ptr;
typedef shared_ptr<iGame> sh_ptr;

class Game : public iGame
{
private:
    sh_ptr actualGame;
    std::vector<sh_ptr> games;
public:

    Game();
    ~Game();
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();

    // iGame interface
    void SendMessage(MSG msg);
};

#endif // GAME_H
