#include "MainGame.h"

#include "Factory.h"

#include "interfaces/iGameObject.h"

#include "graphics/Window.h"

#include "main/objects/World.h"

MainGame::MainGame(iGame *_game)
    : game(_game)
{

}

MainGame::~MainGame()
{

}

void MainGame::Init()
{
    Window win(800,600,"Dungeon",false);
    _world = Factory::createWorld("Contents/MainGame/worlds/world0.json");
}

void MainGame::Update(float dt)
{
    _world->Update(dt);
}

void MainGame::SendMessage(MSG msg, void *content)
{

}

void MainGame::Render()
{
    _world->Render();




}

void MainGame::Dispose()
{

    delete _world;
}
