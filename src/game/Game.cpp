#include "Game.h"

#include "game/menu/MenuGame.h"
#include "game/main/MainGame.h"

#include "graphics/Window.h"

#include "assets/Script.h"

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
    Script script("Contents/keys.lua");
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
