
#include "Painter.h"
#include <iostream>

utils::Painter::Painter() {}

void utils::Painter::paint(game::GameField *gameField, entity::Farmer *farmer, entity::Mole *moles)
{
    int **field = gameField->getField();
    const utils::Vector2 *size = gameField->getSize();
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < size->getX(); ++i)
    {
        for(int j = 0; j < size->getY(); ++j)
        {
            if(i == farmer->getLocation()->getX() && j == farmer->getLocation()->getY())
            {
                std::cout << "F   ";
                continue;
            }
            if(field[i][j] == 1)
            {
                std::cout << "1   ";
            }
            else if(field[i][j] = 0)
            {
                std::cout << "0   ";
            }
        }
        std::cout << std::endl;
    }
}
