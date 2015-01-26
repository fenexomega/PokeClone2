#ifndef CHANGEGAME_H
#define CHANGEGAME_H

#include "interfaces/iCommand.h"
#include "interfaces/iGame.h"

class changeGame : public iCommand
{
private:
    iGame *game;
public:
    changeGame(iGame *_game);
    ~changeGame();
    // iCommand interface
    void Run();
};

#endif // CHANGEGAME_H
