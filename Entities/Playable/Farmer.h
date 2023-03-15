
#ifndef TASK_2_FARMER_H
#define TASK_2_FARMER_H

#include "../Character.h"
#include "../../Utils/Vector2.h"
#include "../../Game.h"
#include <vector>


class Game;

//enum FarmerStatus
//{
//    Moving,
//    AfterAttack
//};

class Farmer :public Character
{
public:
    Farmer() = default;
    Farmer(const int speed, const int hitRadius, Vector2 *location, Game *game);

    ~Farmer();

public:
    const int getSpeed() const;
    void setSpeed(const int speed);

    const int getHitRadius() const;
    void setHitRadius(const int hitRadius);

    const Vector2 *getLocation();
    void setLocation(Vector2 *location);

    const Vector2 *getGoalLocation();
    void setGoalLocation(Vector2 *goalLocation);

    void sortMoles(std::vector<Vector2*> &deltas);

    void execAction();

private:
    void findClosestMole();
    void move() override;
    void attack() override;

private:
    int speed;
    int hitRadius;
    Vector2 *location;
    Vector2 *goalLocation = nullptr;

    Game *game;
};



#endif //TASK_2_FARMER_H
