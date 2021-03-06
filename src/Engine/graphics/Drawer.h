#ifndef DRAWER_H
#define DRAWER_H

#include <memory>

#include "graphics/Color.h"
#include "math/Vector2D.h"

class Rect;
class Texture;
class Font;
enum FontAlign : short;

using std::shared_ptr;

class Drawer
{
friend class Font;
private:
    Drawer();
    ~Drawer();
public:
    //Renderizar textura.

    //Colore a tela inteira com a cor escolhida, inclusive o Alpha
    static void clearScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    static void Render(const shared_ptr<Texture>texture, Rect *const rect);
    static void Render(const shared_ptr<Texture>texture, Rect *const  srcrect,Rect *const  destrect);
    static void Render(const shared_ptr<Texture>texture, const int x, const int y);

    static void Render(const shared_ptr<Texture>texture, const Vector2D vec);

    static void Render(const shared_ptr<Texture> texture, const int x, const int y,
                        float angle,const Vector2D center, int offsetx, int offsety);



    static void RenderTo(shared_ptr<Texture>texture = NULL);

    static void RenderText(shared_ptr<Font> font, std::string text, int x, int y,
                           Color color = COLORBLACK,
                           Uint32 lineWrap = 0, short align = 0);

    //Desenha uma linha de x1,y1 a x2,y2
    static void drawLine(Color color,int x1, int y1, int x2, int y2);

    //Desenhar retângulo com a margem esquerda superior. Desenha apenas as arestas
    static void drawRect(Color color, int x, int y, int w, int h);
    static void drawRect(Color color, Rect _rect);


    //Renderiza um retângulo
    static void fillRect(Color color, int x, int y, int w, int h);
    static void fillRect(Color color, Rect _rect);


    static void setColor(Color color);
};

#endif // DRAWER_H
