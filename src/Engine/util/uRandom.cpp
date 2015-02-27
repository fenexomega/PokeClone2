#include "uRandom.h"

void uRandom::initRandomSeed()
{
    srand(time(NULL));
}

bool uRandom::byChance(float percent)
{
    return (rand()%100 + 1) <= percent;
}

int uRandom::getInt(int num)
{
    return rand()%num;
}
