
#ifndef TASK_2_MOLE_H
#define TASK_2_MOLE_H

#include "../Character.h"
#include "../../Utils/Vector2.h"

namespace entity
{
enum MoleGender
{
    Male,
    Female
};

class Mole
{
public:
    Mole() = default;
    Mole(MoleGender gender, utils::Vector2 *location);

    ~Mole();

public:
    const utils::Vector2 *getLocation();
    void setLocation(utils::Vector2 *location);

    const MoleGender getGender() const;
    void setGender(MoleGender gender);

    const bool isUnderGround() const;
    void setUnderGround(const bool underGround);

private:
    void createLocation();

private:
    utils::Vector2 *location;
    MoleGender gender;
    bool underGround = true;


};

} // entity

#endif //TASK_2_MOLE_H
