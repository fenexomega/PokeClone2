#include "Tilemap.h"

#include "io/FileLoader.h"

#define PRINT(X) std::cout << X << std::endl

Tilemap::Tilemap(std::string jsonFile)
{
    Json::Value json, *object = FileLoader::LoadJson(jsonFile);
    json = *object;
    m_size.x = json["height"].asInt();
    m_size.y = json["width"].asInt();

    int ArraySize = json["tilesets"].size();
    PRINT(ArraySize);
    for(int i = 0; i < ArraySize ; ++i)
    {
        m_tex.push_back(new Texture("Contents/" + json["tilesets"][i]["image"].asString()));
    }



    std::cout << m_size << std::endl;
}

Tilemap::~Tilemap()
{

}

void Tilemap::SendMessage(MSG msg)
{

}

void Tilemap::Update(float dt)
{

}

void Tilemap::Draw()
{

}
