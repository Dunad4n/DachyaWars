
#ifndef TASK_2_GAMEFIELD_H
#define TASK_2_GAMEFIELD_H

#include "Utils/Vector2.h"

namespace game
{
class GameField
{
public:
    GameField() = default;
    GameField(int x, int y);

    ~GameField();
public:
    bool isClear();

    int** getField();
    void setField(int **field);
    void setField(int x, int y);

    const utils::Vector2 *getSize();
    void setSize(utils::Vector2 *size);

private:
    void createField(int x, int y);
    void deleteField();

private:
    int **field;
    utils::Vector2 *size;
};
}


#endif //TASK_2_GAMEFIELD_H
