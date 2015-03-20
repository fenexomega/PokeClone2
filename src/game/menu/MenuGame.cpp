#include "MenuGame.h"

#include "commands/changeGame.h"
#include "commands/exitGame.h"

#include "io/FileLoader.h"

#include "graphics/Window.h"

MenuGame::MenuGame(iGame *_game)
    : game(_game)
{

}

MenuGame::~MenuGame()
{

}

void MenuGame::Init()
{
    static Button *b1 = new Button(Window::getWidth()/2,
                                   Window::getHeight()/2 ,
                             FileLoader::LoadTexture("Contents/Menu/button.png"),
                             FileLoader::LoadTexture("Contents/Menu/buttonMouseOver.png"),
                             new changeGame(game),
                             new Text("Contents/Menu/UbuntuMono-B.ttf",
                                                       "Iniciar",
                                                       24));

    static Button *b2 = new Button(Window::getWidth()/2,
                                    Window::getHeight()/2 + 100,
                             FileLoader::LoadTexture("Contents/Menu/button.png"),
                             FileLoader::LoadTexture("Contents/Menu/buttonMouseOver.png"),
                             new exitGame,
                             new Text("Contents/Menu/UbuntuMono-B.ttf",
                                                       "Sair",
                                                       24));

    text = new Text("Contents/Menu/slkscr.ttf","VACILATION",60,COLORWHITE);
    text2 = new Text("Contents/Menu/slkscr.ttf","GAME",60,COLORWHITE);

    buttons.push_back(b1);
    buttons.push_back(b2);
}

void MenuGame::Update(float dt)
{
    for(auto i : buttons)
        i->Update();
}

void MenuGame::Render()
{
    static int posx = 220;
    static int posy = 80;
    text->Render(posx,posy);
    text2->Render(posx + 90,posy + 80);

    for(auto i : buttons)
        i->Render();
}

void MenuGame::Dispose()
{
    for(auto i : buttons)
        delete i;
    buttons.clear();
    delete text;
    delete text2;
}


void MenuGame::SendMessage(MSG msg, void *content)
{
}
