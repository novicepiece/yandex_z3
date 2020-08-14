#include "Random.h"

int randomRange(int bottom, int up)
{
    return (rand() % (up - bottom)) + bottom;
}
