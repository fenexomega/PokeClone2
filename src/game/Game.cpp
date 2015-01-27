#include "Game.h"

#include "game/menu/MenuGame.h"
#include "game/main/MainGame.h"

#define ADD_GAME(GAME) games.push_back(sh_ptr(GAME))

Game::Game()
{
    ADD_GAME(new MenuGame(this));
    ADD_GAME(new MainGame(this));
    actualGame = games[0];
}

Game::~Game()
{

}

void Game::Init()
{
    actualGame->Init();
}

void Game::Update(float dt)
{
    actualGame->Update(dt);

}

void Game::Render()
{
    actualGame->Render();
}

void Game::Dispose()
{
    actualGame->Dispose();
}


void Game::SendMessage(MSG msg)
{
    actualGame->Dispose();
    actualGame = games.at(msg.id);
    actualGame->Init();
}
