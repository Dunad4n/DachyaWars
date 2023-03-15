
#include "Painter.h"
#include <iostream>
#include <vector>

Painter::Painter() {}

Painter::Painter(int x, int y)
{
    paintedField = new std::string *[x];
    for(int i = 0; i < x; ++i)
    {
        paintedField[i] = new std::string[y];
    }
    this->rows = x;
}

Painter::~Painter()
{
    for(int i = rows - 1; i >= 0; --i)
    {
        delete[] paintedField[i];
    }
    delete[] paintedField;
}

void Painter::paint(GameField *gameField, Farmer *farmer, std::vector<Mole*> &moles)
{
    int **field = gameField->getField();
    const Vector2 *size = gameField->getSize();
    fillField(field, size, farmer, moles);
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < size->getX(); ++i)
    {
        for(int j = 0; j < size->getY(); ++j)
        {
            std::cout << paintedField[i][j];
        }
        std::cout << std::endl;
    }
}

void Painter::fillField(int **field, const Vector2 *size, Farmer *farmer, std::vector<Mole *> &moles)
{

    for(int i = 0; i < size->getX(); ++i)
    {
        for(int j = 0; j < size->getY(); ++j)
        {
            if(field[i][j] == 1)
            {
                paintedField[i][j] = "P     ";
            }
            else if(field[i][j] == 0)
            {
                paintedField[i][j] = "X     ";
            }
        }
    }
    for(int i = 0; i < moles.size(); ++i)
    {
        if(moles[i]->isUnderGround())
        {
            paintedField[moles[i]->getLocation()->getX()][moles[i]->getLocation()->getY()] = "U";
        }
        else if(moles[i]->isOnTheGround())
        {
            paintedField[moles[i]->getLocation()->getX()][moles[i]->getLocation()->getY()] = "M";
        }
        else if(moles[i]->isAttacked())
        {
            paintedField[moles[i]->getLocation()->getX()][moles[i]->getLocation()->getY()] = "A";
        }
        else if(moles[i]->isRest())
        {
            paintedField[moles[i]->getLocation()->getX()][moles[i]->getLocation()->getY()] = "R";
        }
        if(moles[i]->isMan())
        {
            paintedField[moles[i]->getLocation()->getX()][moles[i]->getLocation()->getY()] += "_M   ";
        }
        else if(moles[i]->isWoman())
        {
            paintedField[moles[i]->getLocation()->getX()][moles[i]->getLocation()->getY()] += "_W   ";
        }
    }
    paintedField[farmer->getLocation()->getX()][farmer->getLocation()->getY()] = "FARM  ";
}
