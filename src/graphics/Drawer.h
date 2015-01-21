#ifndef DRAWER_H
#define DRAWER_H

#include "assets/Texture.h"
#include "graphics/Color.h"

class Drawer
{
    friend class Texture;

private:
    Drawer();
    ~Drawer();
    static void renderTexture(SDL_Texture* texture,SDL_Rect *rect);
public:
    //Renderizar textura.

    //Colore a tela inteira com a cor escolhida, inclusive o Alpha
    static void clearScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    //Desenha uma linha de x1,y1 a x2,y2
    static void drawLine(Color color,int x1, int y1, int x2, int y2);

    //Desenhar retângulo com a margem esquerda superior. Desenha apenas as aretas
    static void drawRect(Color color, int x, int y, int w, int h);

    //Renderiza um retângulo
    static void fillRect(Color color, int x, int y, int w, int h);
};

#endif // DRAWER_H
