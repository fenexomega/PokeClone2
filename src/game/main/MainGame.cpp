#include "MainGame.h"

#include "game/Factory.h"

#include "interfaces/iGameObject.h"

#include "graphics/Window.h"

#include "game/main/objects/WorldContext.h"

MainGame::MainGame(iGame *_game)
    : game(_game)
{

}

MainGame::~MainGame()
{

}

void MainGame::Init()
{
    Window win(1024,768,"Daora",false);
    _world = Factory::createWorldContext("Contents/MainGame/maps/map0.json");
    player = Factory::_player;
}

void MainGame::Update(float dt)
{
    player->Update(dt);
    _world->Update(dt);
}

void MainGame::SendMessage(MSG msg, void *content)
{

}

void MainGame::Render()
{
    _world->Render();

    player->Render();



}

void MainGame::Dispose()
{

    delete player;
    delete _world;
}
