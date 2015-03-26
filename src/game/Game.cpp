#include "Game.h"

#include "menu/MenuGame.h"
#include "main/MainGame.h"

#include "graphics/Window.h"

#include "assets/Script.h"

#define ADD_GAME(GAME) games.push_back(sh_ptr(GAME))

Game::Game()
{
    ADD_GAME(new MenuGame(this));
    ADD_GAME(new MainGame(this));
    _actualGame = games[0];
}

Game::~Game()
{

}

void Game::Init()
{
    _actualGame->Init();
    _previousGame = nullptr;
}

void Game::Update(float dt)
{
    if(_previousGame != nullptr)
    {
        _previousGame->Dispose();
        _previousGame = nullptr;
    }
    _actualGame->Update(dt);

}

void Game::Render()
{
    _actualGame->Render();
}

void Game::Dispose()
{
    _actualGame->Dispose();
}


void Game::SendMessage(MSG msg, void *content)
{
    _previousGame = _actualGame;
    _actualGame = games.at(msg.id);
    _actualGame->Init();

}
