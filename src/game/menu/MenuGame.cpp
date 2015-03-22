#include "MenuGame.h"

#include "commands/changeGame.h"
#include "commands/exitGame.h"

#include "io/FileLoader.h"

#include "graphics/Window.h"
#include "graphics/Drawer.h"

MenuGame::MenuGame(iGame *_game)
    : game(_game)
{

}

MenuGame::~MenuGame()
{

}

void MenuGame::Init()
{
    Window::setHiddenMouseCursor(false);
    Button *b1 = new Button(Window::getWidth()/2,
                                   Window::getHeight()/2 ,
                                   FileLoader::LoadTexture("Contents/Menu/button.png"),
                                   FileLoader::LoadTexture("Contents/Menu/buttonMouseOver.png"),
                                   new changeGame(game),
                                   new Font("Contents/Menu/UbuntuMono-B.ttf",
                                            24), "Iniciar",COLORBLACK);

    Button *b2 = new Button(Window::getWidth()/2,
                                   Window::getHeight()/2 + 100,
                                   FileLoader::LoadTexture("Contents/Menu/button.png"),
                                   FileLoader::LoadTexture("Contents/Menu/buttonMouseOver.png"),
                                   new exitGame,
                                   new Font("Contents/Menu/UbuntuMono-B.ttf",
                                            24), "Fechar",COLORBLACK);
    text = new Font("Contents/Menu/slkscr.ttf",60);

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
    Drawer::RenderText(text,"Vacilation",posx,posy,COLORWHITE);
    Drawer::RenderText(text,"Game",posx + 90,posy + 80,COLORWHITE);

    for(auto i : buttons)
        i->Render();
}

void MenuGame::Dispose()
{
    for(auto i : buttons)
        delete i;
    buttons.clear();
    delete text;
}


void MenuGame::SendMessage(MSG msg, void *content)
{
}
