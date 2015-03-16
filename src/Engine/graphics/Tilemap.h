#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>
#include <memory>

#include "assets/Texture.h"
#include "math/Vector2D.h"


typedef struct
{
    std::vector<Uint32> data;
    Vector2D size;
    bool visible;
}Layer;


//TODO fazer isso usar graphics/tiles/SpriteSheet.h
class Tilemap
{
private:

    class TileImage
    {
    public:
        std::shared_ptr<Texture> tex;
        std::string name;
        Vector2D size;
        TileImage(std::shared_ptr<Texture> _tex,std::string _name,Vector2D _imageSize)
            :   tex(_tex), name(_name), size(_imageSize) {}
        ~TileImage()
        {
        }
    };

    void generateTileMap();
public:

    std::vector<Rect> m_tileRects;
    Vector2D m_size;
    Vector2D m_tileSize;
    std::shared_ptr<Texture> tileTexture;

    std::vector<TileImage* >m_tileImages;
    std::vector<Layer> layers;

    Tilemap(std::string jsonFile);

    void Render(Vector2D pos);

    void Render(int x, int y);
    std::vector<Uint32> operator[](int i);
    Vector2D getLayerSize();
    ~Tilemap();

    std::vector<Uint32> getLayers(int i) const;
};


#endif // TILEMAP_H
