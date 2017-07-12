#include "Spaceship.hpp"

Spaceship::Spaceship(std::string type, int speed)
{
    this->type = type;
    this->speed = speed;
}
bool Spaceship::operator==(Spaceship other)
{
    // divide by 100 to get the two lasts digits as a decimal number and discard them by casting to int because we only care about the first digit.
    return (int) this->speed / 100 == (int) other.speed / 100;
}