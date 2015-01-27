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
    map = new Tilemap("Contents/tiledmap.json");
    player = Factory::createPlayer("Contents/MainGame/player.json",nullptr);
//    player = new Player("Contents/MainGame/playersprite.png",
//                        Vector2D<int>(10,10),Rect(400,400,32,32),
//                        4,new PlayerInput());
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
    map->Render(0,0);
    player->Render();
}

void MainGame::Dispose()
{
    delete player;
}
