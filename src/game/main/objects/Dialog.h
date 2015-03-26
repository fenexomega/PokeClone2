#ifndef DIALOG_H
#define DIALOG_H

#include <iostream>
#include <memory>

class Font;


using std::shared_ptr;
using ptr_font = shared_ptr<Font>;


class Dialog
{
private:
    std::string _text;
    ptr_font _font;
public:
    Dialog(std::string text,ptr_font font);
    void Render();
    ~Dialog();
};

#endif // DIALOG_H
