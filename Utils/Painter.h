
#ifndef TASK_2_PAINTER_H
#define TASK_2_PAINTER_H

#include "../GameField.h"
#include "../Entities/Playable/Farmer.h"
#include "../Entities/Playable/Mole.h"

namespace utils
{

class Painter
{
public:
    Painter();


public:
    void paint(game::GameField *gameField, entity::Farmer *farmer, entity::Mole *moles);
};

} // utils

#endif //TASK_2_PAINTER_H
