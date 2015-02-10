#include "MainGame.h"

#include "game/Factory.h"

#include "interfaces/iGameObject.h"

MainGame::MainGame(iGame *_game)
    : game(_game)
{

}

MainGame::~MainGame()
{

}

void MainGame::Init()
{
    actualWorld = Factory::createWorld("Contents/MainGame/maps/map0.json");
    player = Factory::player;

}

void MainGame::Update(float dt)
{
    player->Update(dt);
    actualWorld->Update(dt);

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
