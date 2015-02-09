#include "DecorationGraphic.h"
#include "graphics/Drawer.h"
#include "io/FileLoader.h"

DecorationGraphic::DecorationGraphic(std::string TexFile, iComponentMediator *mediator)
    : cGraphic(mediator)
{
    _tex = FileLoader::LoadTexture(TexFile);
}

DecorationGraphic::~DecorationGraphic()
{

}



void DecorationGraphic::receiveMessage(int msg)
{
}

void DecorationGraphic::Update(iGameObject *obj, float dt)
{
}

void DecorationGraphic::Render(iGameObject *obj)
{
    Drawer::Render(_tex,&obj->rect);
}
