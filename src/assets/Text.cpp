#include "Text.h"

Text::Text(std::string _path,int _textSize,Rect _rect) :
    iAsset(_path,AS_FONT), textSize(_textSize), rect(_rect)
{

}

Text::~Text()
{

}

