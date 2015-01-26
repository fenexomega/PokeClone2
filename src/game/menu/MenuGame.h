#ifndef MENUGAME_H
#define MENUGAME_H

#include <vector>
#include <memory>

#include "gui/Button.h"
#include "interfaces/iScene.h"


class MenuGame : public iGame
{
private:
    std::vector<Button *> buttons;
    iGame *game;
public:
    MenuGame(iGame *_game);
    ~MenuGame();
    // iGame interface
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();

    // iGame interface
    void SendMessage(MSG msg);
};

#endif // MENUGAME_H
