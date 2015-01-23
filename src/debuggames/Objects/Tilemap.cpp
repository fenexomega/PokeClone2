#include "Tilemap.h"

#include "io/FileLoader.h"
#include "graphics/Window.h"
#define PRINT(X) std::cout << X << std::endl

//TODO Pegar as otras coisas do json que podem ser relevantes

Tilemap::Tilemap(std::string jsonFile)
{
    Json::Value json, *object = FileLoader::LoadJson(jsonFile);
    json = *object;
    m_size.x = json["height"].asInt();
    m_size.y = json["width"].asInt();

    m_tileSize.x = json["tileheight"].asInt();
    m_tileSize.y = json["tilewidth"].asInt();



    int ArraySize = json["tilesets"].size();
    PRINT(ArraySize);
    for(int i = 0; i < ArraySize ; ++i)
    {
        m_tileImages.push_back(TileImage(new Texture("Contents/" + json["tilesets"][i]["image"].asString()),
                                        json["tilesets"][i]["name"].asString(),
                                        Vector2D<int>(json["tilesets"][i]["imagewidth"].asInt(),
                                                      json["tilesets"][i]["imageheight"].asInt()) ));
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
    Rect srcrect;
    Rect destrect;

//    Vector2D<int> tilesInScreen(Window::getWidth()/m_tileSize.x,
//                                Window::getHeight()/m_tileSize.y);

    //TODO Otimizar esse código
    for(Layer layer : layers)
    {
        //Pegar o tamanho da imagem em tiles
        Vector2D<int> imageSizeIT(m_tileImages[0].size.x / m_tileSize.x,
                                  m_tileImages[0].size.y / m_tileSize.y);
        //Para cada valor na camada de tiles
        for(int i = 0; i < layer.data.size(); ++i)
        {
            int value = layer.data[i];
            //Gerar um novo retangulo src
            srcrect = Rect( ((value-1)%imageSizeIT.x) * m_tileSize.x,
                               ((value-1)/imageSizeIT.x) * m_tileSize.y,
                               m_tileSize.x,m_tileSize.y);
            //Gerar um novo retangulo dest
            destrect = Rect( (i%m_size.x) * m_tileSize.x,
                                (i/m_size.y) * m_tileSize.y,
                                m_tileSize.x,m_tileSize.y);

            //Renderizar na tela
            TileImage tileimage = m_tileImages[0];
            tileimage.tex->Render(srcrect,destrect);

        }

    }

}
