#ifndef IASSET
#define IASSET

#define AS_TEXTURE 0
#define AS_JSON    1
#define AS_SOUND   2
#define AS_FONT    3

#include <iostream>

class iAsset
{
private:

public:
    std::string filePath;
    int id;

    iAsset(std::string _filePath,int _id)
        : filePath(_filePath), id(_id) {}

};

#endif // IASSET

