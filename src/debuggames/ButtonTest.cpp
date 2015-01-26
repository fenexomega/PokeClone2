#include "ButtonTest.h"
#include "Objects/DummyCommand.h"

ButtonTest::ButtonTest()
{

}

ButtonTest::~ButtonTest()
{

}



void ButtonTest::Init()
{
    button = new Button(100,100,
                        new Texture("Contents/button.png")
                        ,new Texture("Contents/buttonMouseOver.png"),
                        new DummyCommand(),
                        new Text("Contents/UbuntuMono-B.ttf","Pressione",16,COLORBLACK));
}

void ButtonTest::Update(float dt)
{
    button->Update();
}

void ButtonTest::Render()
{
    button->Render();
}

void ButtonTest::Dispose()
{
    delete button;
}
