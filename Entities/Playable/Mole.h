
#ifndef TASK_2_MOLE_H
#define TASK_2_MOLE_H

#include "../Character.h"

namespace entity
{
enum MoleGender
{
    Male,
    Female
};

class Mole :public Character
{
public:
    Mole() = default;
    Mole(MoleGender gender);

public:
    const MoleGender getGender() const;
    const bool isUnderGround() const;

    void setGender(MoleGender gender);
    void setUnderGround(const bool underGround);

private:
    MoleGender gender;
    bool underGround = true;
};

} // entity

#endif //TASK_2_MOLE_H
