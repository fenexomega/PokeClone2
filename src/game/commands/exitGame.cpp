#include "exitGame.h"

#include "Engine.h"

exitGame::exitGame()
{

}

exitGame::~exitGame()
{

}



void exitGame::Run()
{
    Engine::Exit();
}
