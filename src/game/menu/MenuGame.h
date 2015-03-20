#ifndef MENUGAME_H
#define MENUGAME_H

#include <vector>
#include <memory>

#include "gui/Button.h"
#include "interfaces/iGame.h"

class MenuGame : public iGame
{
private:
    std::vector<Button *> buttons;
    iGame *game;
    Text *text{}, *text2;
public:
    MenuGame(iGame *_game);
    ~MenuGame();
    // iGame interface
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();

    // iGame interface
    void SendMessage(MSG msg,void *content);
};

#endif // MENUGAME_H
