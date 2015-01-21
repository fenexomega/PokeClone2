#ifndef URANDOM_H
#define URANDOM_H
#include <cstdlib>
#include <ctime>

class uRandom
{
public:
    static bool byChance(float percent);
    static void initRandomSeed();
    static int getInt(int num);
};

#endif // URANDOM_H
