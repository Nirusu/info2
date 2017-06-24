#include <vector>
#include "Orange.hpp"

Orange::Orange(int sweetness, int juicyness)
{
    this->sweetness = sweetness;
    this->juicyness = juicyness;
}

bool Orange::operator<(Orange other)
{
    if (this->sweetness == other.sweetness) // use juicyness to decide if both oranges share the same sweetness
    {
        return this->juicyness < other.juicyness;
    }
    return this->sweetness < other.sweetness;
}
