#include "DecorationGraphic.h"
#include "graphics/Drawer.h"
#include "io/FileLoader.h"
#include "util/Logger.h"

DecorationGraphic::DecorationGraphic(std::string TexFile, iComponentMediator *mediator, bool active)
    : cGraphic(mediator),_active(active)
{
    _tex = FileLoader::LoadTexture(TexFile);
}

DecorationGraphic::~DecorationGraphic()
{

}



void DecorationGraphic::receiveMessage(int msg)
{
    switch(msg)
    {
        case DISSAPEAR:
        {
            _active = !_active;

        }break;
    }

}

void DecorationGraphic::Update(iGameObject *obj, float dt)
{

}

void DecorationGraphic::Render(iGameObject *obj)
{
    if(_active)
        Drawer::Render(_tex,&obj->rect);
}
