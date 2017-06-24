#include "Apple.hpp"

Apple::Apple(int sweetness, int juicyness)
{
    this->sweetness = sweetness;
    this->juicyness = juicyness;
}

bool Apple::operator<(Apple other)
{
    int sum_first_apple = 3 * this->sweetness + this->juicyness;
    int sum_other_apple = 3 * other.sweetness + other.juicyness;

    return sum_first_apple < sum_other_apple;
}