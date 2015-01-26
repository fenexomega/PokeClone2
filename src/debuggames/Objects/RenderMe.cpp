#include "RenderMe.h"

#include "io/FileLoader.h"
#include "graphics/Drawer.h"

RenderMe::RenderMe(std::string path)
{
    texture = new Texture(path);
}

void RenderMe::Render()
{
    Drawer::Render(texture,0,0);
}

void RenderMe::Update(float dt)
{

}

RenderMe::~RenderMe()
{
    delete texture;
}

