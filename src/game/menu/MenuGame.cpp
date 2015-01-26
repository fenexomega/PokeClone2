#include "MenuGame.h"

#include "commands/changeGame.h"

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
                             new Texture("Contents/Menu/button.png"),
                             new Texture("Contents/Menu/buttonMouseOver.png"),
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


void MenuGame::SendMessage(MSG msg)
{
}
