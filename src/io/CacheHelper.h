#ifndef CACHEHELPER_H
#define CACHEHELPER_H


#include <memory>
#include <map>
#include "interfaces/iAsset.h"



//TODO implement as singleton
//TODO Use shared_ptr
class CacheHelper
{
private:
    static std::map<std::string,std::shared_ptr<iAsset> > files;
public:
    CacheHelper();
    ~CacheHelper();
};

#endif // CACHEHELPER_H
