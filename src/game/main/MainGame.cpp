#include "MainGame.h"

#include "game/Factory.h"

#include "game/main/components/PlayerInput.h"


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
    enemy = Factory::createEnemy("Contents/MainGame/enemy.json",actualWorld);
}

void MainGame::Update(float dt)
{
    player->Update(dt);
    enemy->Update(dt);
}

void MainGame::SendMessage(MSG msg)
{
}

void MainGame::Render()
{
    actualWorld->Render();
    player->Render();
    enemy->Render();
}

void MainGame::Dispose()
{
    delete enemy;
    delete player;
    delete actualWorld;
}
