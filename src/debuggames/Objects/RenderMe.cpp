#include "RenderMe.h"

#include "io/FileLoader.h"
#include "graphics/Drawer.h"

RenderMe::RenderMe(std::string path)
{
    texture = new Texture(path);
}

void RenderMe::Draw()
{
    texture->Render(0,0);
}

void RenderMe::Update(float dt)
{

}

RenderMe::~RenderMe()
{
    delete texture;
}


void RenderMe::SendMessage(MSG msg)
{
}
