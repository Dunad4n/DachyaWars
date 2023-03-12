//
// Created by sosis on 12.03.2023.
//

#include "Vector2.h"

namespace utils
{
Vector2::Vector2() {}

Vector2::Vector2(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

const int Vector2::getX() const
{
    return this->x;
}

const int Vector2::getY() const
{
    return this->y;
}

void Vector2::setX(const int x)
{
    this->x = x;
}

void Vector2::setY(const int y)
{
    this->y = y;
}
} // utils