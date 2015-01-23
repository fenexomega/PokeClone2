#include "Tilemap.h"

#include "io/FileLoader.h"

#define PRINT(X) std::cout << X << std::endl

//TODO Pegar as otras coisas do json que podem ser relevantes
//TODO ver como renderizar esses tiles no mapa

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

    Json::Value jsonLayers = json["layers"];
    ArraySize = jsonLayers.size();

    for(int i = 0; i < ArraySize; ++i)
    {
        Layer l1;
        l1.size = Vector2D<int>(jsonLayers[i]["width"].asInt(),jsonLayers[i]["height"].asInt());
        l1.visible = jsonLayers[i]["visible"].asBool();

        for(auto iit = jsonLayers[i]["data"].begin();
            iit != jsonLayers[i]["data"].end();
            ++iit)
        {
                l1.data.push_back((*iit).asInt());
        }

        layers.push_back(l1);
    }


    PRINT(layers.size());

//    std::cout << m_size << std::endl;
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
