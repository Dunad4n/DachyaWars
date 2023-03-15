
#ifndef TASK_2_MOLE_H
#define TASK_2_MOLE_H

#include "../Character.h"
#include "../../Utils/Vector2.h"
#include "../../Game.h"


enum MoleGender
{
    Male,
    Female
};

enum MoleStatus
{
    OnTheGround,
    UnderGround,
    Attacked,
    Rest
};

class Game;

class Mole :public Character
{
public:
    Mole() = default;
    Mole(MoleGender gender, Vector2 *location, Game *game);

    ~Mole();

public:
    Vector2 *getLocation();
    void setLocation(Vector2 *location);

    const MoleGender getGender() const;
    void setGender(MoleGender gender);

    MoleStatus getStatus();
    void setStatus(MoleStatus status);

    bool isUnderGround();
    bool isOnTheGround();
    bool isAttacked();
    bool isMan();
    bool isWoman();
    bool isRest();

    void execAction();
private:
    Vector2* chooseTile();
    std::vector<Vector2*>& getTilesAround(std::vector<Vector2*> &tiles);
    void filterTiles(std::vector<Vector2*> &tiles);
    void filterTilesForAttack(std::vector<Vector2*> &tiles);
    void reProduct();

    void move() override;
    void attack() override;

private:
    Vector2 *location;
    MoleGender gender;
    MoleStatus status = UnderGround;
    Game *game;
};

#endif //TASK_2_MOLE_H
