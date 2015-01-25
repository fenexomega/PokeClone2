#ifndef DRAWER_H
#define DRAWER_H

#include "assets/Texture.h"
#include "graphics/Color.h"
#include "physics/Rect.h"
#include "math/Vector2D.h"

class Drawer
{
private:
    Drawer();
    ~Drawer();

public:
    //Renderizar textura.

    //Colore a tela inteira com a cor escolhida, inclusive o Alpha
    static void clearScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    static void Render(Texture *texture, Rect *rect);
    static void Render(Texture* texture,Rect *srcrect,Rect *destrect);
    static void Render(Texture *texture, int x, int y);
    static void Render(Texture *texture,Vector2D<int> vec);



    static void RenderTo(Texture *texture = NULL);

    //Desenha uma linha de x1,y1 a x2,y2
    static void drawLine(Color color,int x1, int y1, int x2, int y2);

    //Desenhar retângulo com a margem esquerda superior. Desenha apenas as aretas
    static void drawRect(Color color, int x, int y, int w, int h);

    //Renderiza um retângulo
    static void fillRect(Color color, int x, int y, int w, int h);

    static void setColor(Color color);
};

#endif // DRAWER_H
