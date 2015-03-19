#ifndef EXITGAME_H
#define EXITGAME_H

#include "interfaces/iCommand.h"

class exitGame : public iCommand
{
public:
    exitGame();
    ~exitGame();

    // iCommand interface
public:
    void Run();
};

#endif // EXITGAME_H
