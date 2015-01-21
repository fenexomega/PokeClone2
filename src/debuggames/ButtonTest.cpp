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
                        new DummyCommand());
}

void ButtonTest::Update(float dt)
{
    button->Update(real);
}

void ButtonTest::Draw()
{
    button->Draw();
}

void ButtonTest::Dispose()
{
    delete button;
}
