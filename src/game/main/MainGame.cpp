#include "MainGame.h"

#include "game/Factory.h"



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
    enemy = Factory::createEnemy("Contents/MainGame/enemy.json",actualWorld,Vector2D<int>(150,60));
    enemy2 = Factory::createEnemy("Contents/MainGame/enemy.json",actualWorld,Vector2D<int>(600,60));
    object = Factory::createInteractive("",actualWorld,Vector2D<int>(400,400));
}

void MainGame::Update(float dt)
{
    player->Update(dt);
    enemy->Update(dt);
    enemy2->Update(dt);
    object->Update(dt);


}

void MainGame::SendMessage(MSG msg)
{
}

void MainGame::Render()
{
    actualWorld->Render();
    enemy->Render();
    enemy2->Render();
    player->Render();
    object->Render();


}

void MainGame::Dispose()
{
    delete enemy;
    delete enemy2;
    delete player;
    delete actualWorld;
}
