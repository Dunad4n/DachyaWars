//
// Created by sosis on 12.03.2023.
//

#include "Mole.h"

namespace entity
{
Mole::Mole(MoleGender gender)
{
    this->gender = gender;
}

const MoleGender Mole::getGender() const
{
    return this->gender;
}

void Mole::setGender(MoleGender gender)
{
    this->gender = gender;
}

const bool Mole::isUnderGround() const
{
    return this->underGround;
}

void Mole::setUnderGround(const bool underGround)
{
    this->underGround = underGround;
}


} // entity