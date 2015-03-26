#include "MenuGame.h"

#include "commands/changeGame.h"
#include "commands/exitGame.h"

#include "io/FileLoader.h"

#include "graphics/Window.h"
#include "graphics/Drawer.h"

#include "Factory.h"

MenuGame::MenuGame(iGame *_game)
    : game(_game)
{

}

MenuGame::~MenuGame()
{

}

void MenuGame::Init()
{
    auto font = FileLoader::LoadFont("Contents/Menu/UbuntuMono-B.ttf",24);

    Window::setHiddenMouseCursor(false);
    Button *b1 = new Button(Window::getWidth()/2,
                            Window::getHeight()/2 ,
                            FileLoader::LoadTexture("Contents/Menu/button.png"),
                            FileLoader::LoadTexture("Contents/Menu/buttonMouseOver.png"),
                            new changeGame(game),
                            font,
                            "Iniciar",COLORBLACK);

    Button *b2 = new Button(Window::getWidth()/2,
                            Window::getHeight()/2 + 100,
                            FileLoader::LoadTexture("Contents/Menu/button.png"),
                            FileLoader::LoadTexture("Contents/Menu/buttonMouseOver.png"),
                            new exitGame,
                            font,
                            "Fechar",COLORBLACK);

    textFont = FileLoader::LoadFont("Contents/Menu/slkscr.ttf",60);
    instFont = FileLoader::LoadFont("Contents/Menu/slkscr.ttf",20);


    buttons.push_back(b1);
    buttons.push_back(b2);

    Factory::Init();
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
    Drawer::RenderText(textFont,"Vacilation",posx,posy,COLORWHITE);
    Drawer::RenderText(textFont,"Game",posx + 90,posy + 80,COLORWHITE);

    Drawer::RenderText(instFont,"Use wasd para mover-se. K e L para interagir",0,Window::getHeight() - instFont->textSize(),COLORWHITE);


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
