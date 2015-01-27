#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>

#include "assets/Texture.h"
#include "math/Vector2D.h"


//TODO fazer isso usar graphics/tiles/SpriteSheet.h
class Tilemap
{
private:
    typedef struct
    {
        std::vector<Uint16> data;
        Vector2D<int> size;
        bool visible;
    }Layer;

    class TileImage
    {
    public:
        Texture *tex;
        std::string name;
        Vector2D<int> size;
        TileImage(Texture *_tex,std::string _name,Vector2D<int> _imageSize)
            :   tex(_tex), name(_name), size(_imageSize) {}
        ~TileImage()
        {
            delete tex;
        }
    };

    void generateTileMap();
    std::string getLocationDir(std::string filename);
public:
    Vector2D<int> m_size;
    Vector2D<int> m_tileSize;
    Texture *tileTexture;

    std::vector<TileImage* >m_tileImages;
    std::vector<Layer> layers;

    Tilemap(std::string jsonFile);



    void Render(Vector2D<int> pos);
    void Render(int x, int y);
    std::vector<Uint16> operator[](int i);

    ~Tilemap();

};


#endif // TILEMAP_H
