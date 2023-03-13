//
// Created by sosis on 12.03.2023.
//

#include "Farmer.h"

entity::Farmer::Farmer(const int speed, const int hitRadius, utils::Vector2  *location)
{
    this->speed = speed;
    this->hitRadius = hitRadius;
    this->location = location;
}

entity::Farmer::~Farmer()
{
    delete location;
}

const int entity::Farmer::getSpeed() const
{
    return this->speed;
}

void entity::Farmer::setSpeed(const int speed)
{
    this->speed = speed;
}

const int entity::Farmer::getHitRadius() const
{
    return this->hitRadius;
}

void entity::Farmer::setHitRadius(const int hitRadius)
{
    this->hitRadius = hitRadius;
}

const utils::Vector2* entity::Farmer::getLocation()
{
    return location;
}

void entity::Farmer::setLocation(utils::Vector2 *location)
{
    this->location = location;
}
