#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>

#include "assets/Texture.h"
#include "interfaces/iGameObject.h"
#include "math/Vector2D.h"

class Layer
{
public:
    std::vector<Uint16> data;
    Vector2D<int> size;
    bool visible;
};


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


class Tilemap : public iGameObject
{
private:


    void generateTileMap();


public:
    Vector2D<int> m_pos;
    Vector2D<int> m_size;
    Vector2D<int> m_tileSize;
    Texture *tileTexture;

    std::vector<TileImage* >m_tileImages;
    std::vector<Layer> layers;

    Tilemap(std::string jsonFile);

    // iGameObject interface
    void SendMessage(MSG msg);
    void Update(float dt);
    void Draw();

    ~Tilemap();

};

class POSMSG : public MSG
{
private:
    Vector2D<int> pos;
    POSMSG()
    {
        id = 1;
    }
};


#endif // TILEMAP_H
