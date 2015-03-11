#include "MenuGame.h"

#include "commands/changeGame.h"

#include "io/FileLoader.h"

MenuGame::MenuGame(iGame *_game)
    : game(_game)
{

}

MenuGame::~MenuGame()
{

}

void MenuGame::Init()
{
    static Button *aux = new Button(200,200,
                             FileLoader::LoadTexture("Contents/Menu/button.png"),
                             FileLoader::LoadTexture("Contents/Menu/buttonMouseOver.png"),
                             new changeGame(game),
                             new Text("Contents/Menu/UbuntuMono-B.ttf",
                                                       "Iniciar",
                                                       24));
    buttons.push_back(aux);
}

void MenuGame::Update(float dt)
{
    for(auto i : buttons)
        i->Update();
}

void MenuGame::Render()
{
    for(auto i : buttons)
        i->Render();
}

void MenuGame::Dispose()
{
    for(auto i : buttons)
        delete i;
    buttons.clear();
}


void MenuGame::SendMessage(MSG msg, void *content)
{
}
