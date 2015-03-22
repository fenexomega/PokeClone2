#include "MainGame.h"

#include "Factory.h"

#include "interfaces/iGameObject.h"

#include "graphics/Window.h"

#include "main/objects/World.h"

#include "systems/sysInput.h"

MainGame::MainGame(iGame *_game)
    : game(_game)
{

}

MainGame::~MainGame()
{

}

void MainGame::Init()
{
    Window::setHiddenMouseCursor(true);
    _world = Factory::createWorld("Contents/MainGame/worlds/world0.json");
}

void MainGame::Update(float dt)
{
    _world->Update(dt);
    if(sysInput::isKeyDown(SDL_SCANCODE_ESCAPE))
        game->SendMessage({0},NULL);
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
