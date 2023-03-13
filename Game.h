
#ifndef TASK_2_GAME_H
#define TASK_2_GAME_H



#include "GameField.h"
#include "Entities/Playable/Farmer.h"
#include "Entities/Playable/Mole.h"

namespace game
{

enum GameStage
{
    FarmerTurn,
    MolesTurn
};

class Game
{
public:
    Game();
    Game(GameField *gameField, entity::Farmer *farmer, entity::Mole *moles);

    ~Game();
public:
    void run();

private:
    void createMoles(int maleMoles, int femaleMoles);
    utils::Vector2 *createMoleLocation();

private:
    GameField *gameField;
    entity::Farmer *farmer;
    entity::Mole *moles;
    GameStage gameStage;
};
}


#endif //TASK_2_GAME_H
