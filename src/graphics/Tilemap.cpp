#include "Tilemap.h"

#include "io/FileLoader.h"
#include "graphics/Window.h"
#include "graphics/Drawer.h"
#define PRINT(X) std::cout << X << std::endl

//TODO Pegar as otras coisas do json que podem ser relevantes

std::string Tilemap::getLocationDir(std::string filename)
{
    std::string aux;
    int i = filename.find_last_of('/');
    aux.append(filename.substr(0,i) + '/');
    return aux;

}
std::vector<Uint32> Tilemap::getLayers(int i) const
{
    return layers.at(i).data;
}



Tilemap::Tilemap(std::string jsonFile)
{
    Json::Value json = FileLoader::LoadJson(jsonFile);
    std::string Dir = getLocationDir(jsonFile);

    m_size.x = json["height"].asInt();
    m_size.y = json["width"].asInt();

    m_tileSize.x = json["tileheight"].asInt();
    m_tileSize.y = json["tilewidth"].asInt();

    int ArraySize = json["tilesets"].size();
    for(int i = 0; i < ArraySize ; ++i)
    {
        m_tileImages.push_back(new TileImage(FileLoader::LoadTexture(Dir + json["tilesets"][i]["image"].asString()),
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

    tileTexture = std::shared_ptr<Texture>(new Texture(
            m_size.x * m_tileSize.x,
            m_size.y * m_tileSize.y));

//    std::cout << m_size << std::endl;
    generateTileMap();

}

Tilemap::~Tilemap()
{
    for (auto i : m_tileImages)
        delete i;

}


void Tilemap::Render(Vector2D<int> pos)
{
    Drawer::Render(tileTexture,pos);
}

void Tilemap::Render(int x, int y)
{
    Drawer::Render(tileTexture,x,y);

}

std::vector<Uint32> Tilemap::operator[](int i)
{
    return  layers.at(i).data;
}

Vector2D<int> Tilemap::getLayerSize()
{
    return layers.at(0).size;
}

void Tilemap::generateTileMap()
{
    Drawer::RenderTo(tileTexture);
    Rect srcrect;
    Rect destrect;
    Drawer::clearScreen(0,0,0,255);
    //TODO Otimizar esse código
    for(Layer layer : layers)
    {
        //Pegar o tamanho da imagem em tiles
        Vector2D<int> imageSizeIT(m_tileImages[0]->size.x / m_tileSize.x,
                                  m_tileImages[0]->size.y / m_tileSize.y);
        //Para cada valor na camada de tiles
        for(Uint32 i = 0; i < layer.data.size(); ++i)
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
            m_tileRects.push_back(destrect);
            //Renderizar na tela
            TileImage *tileimage = m_tileImages[0];
            Drawer::Render(tileimage->tex,&srcrect,&destrect);

        }

    }
    Drawer::RenderTo(NULL);

}
