
#include "Vector2.h"


utils::Vector2::Vector2() {}

utils::Vector2::Vector2(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

utils::Vector2::~Vector2() {}

const int utils::Vector2::getX() const
{
    return this->x;
}

const int utils::Vector2::getY() const
{
    return this->y;
}

void utils::Vector2::setX(const int x)
{
    this->x = x;
}

void utils::Vector2::setY(const int y)
{
    this->y = y;
}
