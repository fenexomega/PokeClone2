#include "cGraphic.h"


cGraphic::cGraphic(std::string file)
{
    ptr = std::unique_ptr<Texture> (new Texture(file));
}

cGraphic::~cGraphic()
{

}



void cGraphic::Update(iGameObject &obj)
{
    rect = obj.rect;
}

void cGraphic::Draw()
{
    ptr->Render(rect.x,rect.y);
}

void cGraphic::Scale(float w, float h)
{
    ptr->Scale(w,h);
}
