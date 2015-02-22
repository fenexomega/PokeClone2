#include "changeGame.h"

changeGame::changeGame(iGame *_game)
    : game(_game)
{

}

changeGame::~changeGame()
{

}



void changeGame::Run()
{
    MSG msg = {1};
    game->SendMessage(msg,nullptr);
}
