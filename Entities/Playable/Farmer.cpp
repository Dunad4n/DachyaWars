//
// Created by sosis on 12.03.2023.
//

#include "Farmer.h"

namespace entity
{

Farmer::Farmer(const int speed, const int hitRadius, const utils::Vector2 &location)
{
    this->speed = speed;
    this->hitRadius = hitRadius;
    this->location = location;
}

const int Farmer::getSpeed() const
{
    return this->speed;
}

void Farmer::setSpeed(const int speed)
{
    this->speed = speed;
}

const int Farmer::getHitRadius() const
{
    return this->hitRadius;
}

void Farmer::setHitRadius(const int hitRadius)
{
    this->hitRadius = hitRadius;
}

const utils::Vector2& Farmer::getLocation()
{
    return location;
}

void Farmer::setLocation(const utils::Vector2 &location)
{
    this->location = location;
}
}