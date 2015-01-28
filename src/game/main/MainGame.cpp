#include "MainGame.h"

#include "game/Factory.h"

#include "game/main/PlayerInput.h"


MainGame::MainGame(iGame *_game)
    : game(_game)
{

}

MainGame::~MainGame()
{

}

void MainGame::Init()
{
    actualWorld = new World("Contents/MainGame/map0.json");
    player = Factory::createPlayer("Contents/MainGame/player.json",actualWorld);
}

void MainGame::Update(float dt)
{
    player->Update(dt);
}

void MainGame::SendMessage(MSG msg)
{
}

void MainGame::Render()
{
    actualWorld->Render();
    player->Render();
}

void MainGame::Dispose()
{
    delete player;
    delete actualWorld;
}
