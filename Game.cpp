
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Game.h"
#include "Utils/Painter.h"


game::Game::Game() {}

game::Game::Game(GameField *gameField, entity::Farmer *farmer , entity::Mole *moles)
{
    this->gameField = gameField;
    this->farmer = farmer;
    this->moles = moles;
}

game::Game::~Game()
{
    delete gameField;
    delete farmer;
    delete moles;
}

void game::Game::run()
{
    std::cout << "Input size of game field: x and y" << std::endl;
    int x, y;
    std::cin >> x >> y;
    std::cout << "Input parameters for Farmer: speed, hit radius, location(x) and location(y)" << std::endl;
    int speed, hitRadius, locationX, locationY;
    std::cin >> speed >> hitRadius >> locationX >> locationY;
    std::cout << "Input number of Male moles and Female moles" << std::endl;
    int maleMole, femaleMole;
    std::cin >> maleMole >> femaleMole;

    gameField = new GameField(x, y);
    farmer = new entity::Farmer(speed, hitRadius, new utils::Vector2(locationX, locationY));
    createMoles(maleMole, femaleMole);
    utils::Painter *painter = new utils::Painter();
    painter->paint(gameField, farmer, moles);

    while(!gameField->isClear())
    {
        switch(gameStage)
        {
            case GameStage::FarmerTurn:


            case GameStage::MolesTurn:


            default:
                std::cout << "Incorrect game stage";
                break;
        }

        painter->paint(gameField, farmer, moles);
        std::this_thread::sleep_for(std::chrono::nanoseconds(3000000000));
    }

    delete painter;
}

void game::Game::createMoles(int maleMoles, int femaleMoles)
{
    moles = new entity::Mole[maleMoles + femaleMoles];
    int number = 0;
    for(number = 0; number < maleMoles; ++number)
    {
        moles[number].setGender(entity::MoleGender::Male);
        moles[number].setLocation(createMoleLocation());
    }
    for(; number < maleMoles + femaleMoles; ++number)
    {
        moles[number].setGender(entity::MoleGender::Female);
        moles[number].setLocation(createMoleLocation());
    }
}

utils::Vector2 *game::Game::createMoleLocation()
{
    int x = rand() % gameField->getSize()->getX();
    int y = rand() % gameField->getSize()->getY();
    return new utils::Vector2(x, y);
}
