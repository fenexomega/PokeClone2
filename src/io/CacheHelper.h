#ifndef CACHEHELPER_H
#define CACHEHELPER_H


#include <memory>
#include <map>
#include "interfaces/iAsset.h"



class CacheHelper
{
private:
    static std::map<std::string,std::shared_ptr<iAsset> > files;
public:
    CacheHelper();
    ~CacheHelper();
};

#endif // CACHEHELPER_H
