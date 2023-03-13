
#include "GameField.h"

game::GameField::GameField(int x, int y)
{
    createField(x, y);
    size = new utils::Vector2(x, y);
}

game::GameField::~GameField()
{
    deleteField();
}

int **game::GameField::getField()
{
    return field;
}

void game::GameField::setField(int **field)
{
    this->field = field;
}

void game::GameField::setField(int x, int y)
{
    createField(x, y);
}

const utils::Vector2 *game::GameField::getSize()
{
    return size;
}

void game::GameField::setSize(utils::Vector2 *size)
{
    this->size = size;
}

void game::GameField::createField(int x, int y)
{
    field = new int *[x];
    for(int i = 0; i < x; ++i)
    {
        field[i] = new int [y];
        for(int j = 0; j < y; ++j)
        {
            field[i][j] = 1;
        }
    }
}

void game::GameField::deleteField()
{
    for(int i = size->getX() - 1; i >= 0; --i)
    {
        delete[] field[i];
    }
}

bool game::GameField::isClear()
{
    for(int i = 0; i < size->getX(); ++i)
    {
        for(int j = 0; j < size->getY(); ++j)
        {
            if(field[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}
