
#ifndef TASK_2_FARMER_H
#define TASK_2_FARMER_H

#include "../Character.h"
#include "../../Utils/Vector2.h"

namespace entity
{
class Farmer
{
public:
    Farmer() = default;
    Farmer(const int speed, const int hitRadius, utils::Vector2 *location);

    ~Farmer();

public:
    const int getSpeed() const;
    void setSpeed(const int speed);

    const int getHitRadius() const;
    void setHitRadius(const int hitRadius);

    const utils::Vector2* getLocation();
    void setLocation(utils::Vector2 *location);

private:
    int speed;
    int hitRadius;
    utils::Vector2 *location;

};
}


#endif //TASK_2_FARMER_H
