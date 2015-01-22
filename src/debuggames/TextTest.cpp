#include "TextTest.h"

#include "Objects/CommandTextChanger.h"
#include "Objects/RenderMe.h"

TextTest::TextTest()
{

}

TextTest::~TextTest()
{

}



void TextTest::Init()
{
    text = new Text("Contents/UbuntuMono-B.ttf",
                    "TEXTO LINDO DEMAIS.",
                    72,
                    Color(255,255,255,255));
    Text *tex1 = new Text("Contents/UbuntuMono-B.ttf",
                          "Pressionar",
                          16,
                          Color(0,255,0,255));
    bt = new Button(100,100,
                    new Texture("Contents/button.png"),
                    new Texture("Contents/buttonMouseOver.png"),
                    new CommandTextChanger(text),
                    tex1);

}

void TextTest::Update(float dt)
{
    RenderMe aux("Contents/button.png");
    bt->Update(aux);
}

void TextTest::Draw()
{
    bt->Draw();
    text->Render(0,0);
}

void TextTest::Dispose()
{
    delete text;
}
