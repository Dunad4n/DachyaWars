//
// Created by sosis on 12.03.2023.
//

#include "Mole.h"

entity::Mole::Mole(entity::MoleGender gender, utils::Vector2 *location)
{
    this->gender = gender;
    this->location = location;
}

entity::Mole::~Mole() {}

const entity::MoleGender entity::Mole::getGender() const
{
    return this->gender;
}

void entity::Mole::setGender(entity::MoleGender gender)
{
    this->gender = gender;
}

const bool entity::Mole::isUnderGround() const
{
    return this->underGround;
}

void entity::Mole::setUnderGround(const bool underGround)
{
    this->underGround = underGround;
}

const utils::Vector2 *entity::Mole::getLocation()
{
    return location;
}

void entity::Mole::setLocation(utils::Vector2 *location)
{
    this->location = location;
}


// entity