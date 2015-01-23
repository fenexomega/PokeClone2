#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>

#include "assets/Texture.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"


class Tilemap : public iGameObject
{
private:
    typedef struct{
        std::vector<Uint16> data;
        Vector2D<int> size;
        bool visible;
    }Layer;

    class TileImage{
    public:
        Texture *tex;
        std::string name;
        Vector2D<int> size;

        TileImage(Texture *_tex,std::string _name,Vector2D<int> _imageSize)
            :   tex(_tex), name(_name), size(_imageSize)
        {

        }

    };

public:
    Vector2D<int> m_pos;
    Vector2D<int> m_size;
    Vector2D<int> m_tileSize;
    int tileSize;
    std::vector<TileImage>m_tileImages;
    std::vector<Layer> layers;

    Tilemap(std::string jsonFile);
    ~Tilemap();

    // iGameObject interface
    void SendMessage(MSG msg);
    void Update(float dt);
    void Draw();
};

#endif // TILEMAP_H
