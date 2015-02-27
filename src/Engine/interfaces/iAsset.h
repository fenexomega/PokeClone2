#ifndef IASSET
#define IASSET

#define AS_TEXTURE 0
#define AS_JSON    1
#define AS_SOUND   2
#define AS_FONT    3
#define AS_SCRIPT  4

#include <iostream>

class iAsset
{
private:

public:
    int id;

    iAsset(int _id)
        : id(_id) {}

};

#endif // IASSET

