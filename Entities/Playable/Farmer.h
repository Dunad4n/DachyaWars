
#ifndef TASK_2_FARMER_H
#define TASK_2_FARMER_H

#include "../Character.h"
#include "../../Utils/Vector2.h"

namespace entity
{
class Farmer :public Character
{
public:
    Farmer() = default;
    Farmer(const int speed, const int hitRadius, const utils::Vector2 &location);

public:
    const int getSpeed() const;
    const int getHitRadius() const;
    const utils::Vector2& getLocation();

    void setSpeed(const int speed);
    void setHitRadius(const int hitRadius);
    void setLocation(const utils::Vector2 &location);

private:
    int speed;
    int hitRadius;
    utils::Vector2 location;
};
}


#endif //TASK_2_FARMER_H
