#ifndef SCRIPT_H
#define SCRIPT_H

#include "interfaces/iAsset.h"

class Script : public iAsset
{
public:
    Script(std::string fileName);
    ~Script();
};

#endif // SCRIPT_H
