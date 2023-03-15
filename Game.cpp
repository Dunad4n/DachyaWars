
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Game.h"
#include "Utils/Painter.h"


Game::Game() {}

Game::Game(GameField *gameField, Farmer *farmer , std::vector<Mole*> moles)
{
    this->gameField = gameField;
    this->farmer = farmer;
    this->moles = moles;
}

Game::~Game()
{
    delete gameField;
    delete farmer;
//    delete moles;
}

GameField *Game::getGameField()
{
    return gameField;
}

Randomer *Game::getRandomer()
{
    return randomer;
}

std::vector<Mole *> &Game::getMoles()
{
    return moles;
}

bool Game::molesAlive()
{
    return moles.size() != 0;
}

void Game::run()
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
    farmer = new Farmer(speed, hitRadius, new Vector2(locationX, locationY), this);
    createInitMoles(maleMole, femaleMole);
    Painter *painter = new Painter(x, y);
    painter->paint(gameField, farmer, moles);

    while(!gameField->isClear() && molesAlive())
    {
        switch(gameStage)
        {
            case GameStage::FarmerTurn:
                farmer->execAction();

                gameStage = GameStage::MolesTurn;
                break;
            case GameStage::MolesTurn:

                execMolesAction();
                //findTwoMolesInOneTile();
                gameStage = GameStage::FarmerTurn;
                break;
            default:
                std::cout << "Incorrect game stage";
                break;
        }
        std::this_thread::sleep_for(std::chrono::nanoseconds(2000000000));
        painter->paint(gameField, farmer, moles);
        std::cout << moles.size() << std::endl;
    }

    delete painter;
}

void Game::createInitMoles(int maleMoles, int femaleMoles)
{
//    moles = new entity::Mole[maleMoles + femaleMoles];
//    int number = 0;
//    for(number = 0; number < maleMoles; ++number)
//    {
//        moles[number].setGender(entity::MoleGender::Male);
//        moles[number].setLocation(createMoleLocation());
//    }
//    for(; number < maleMoles + femaleMoles; ++number)
//    {
//        moles[number].setGender(entity::MoleGender::Female);
//        moles[number].setLocation(createMoleLocation());
//    }
    int number;
    for(number = 0; number < maleMoles; ++number)
    {
        moles.push_back(new Mole(MoleGender::Male, createMoleLocation(), this));
    }
    for(; number < maleMoles + femaleMoles; ++number)
    {
        moles.push_back(new Mole(MoleGender::Female, createMoleLocation(), this));
    }
}

Vector2* Game::createMoleLocation()
{
    int x = randomer->random(gameField->getSize()->getX() - 1);
    int y = randomer->random(gameField->getSize()->getY() - 1);
    return new Vector2(x, y);
}

void Game::execMolesAction()
{
    for(int i = 0; i < moles.size(); ++i)
    {
        moles[i]->execAction();
    }
}

void Game::findTwoMolesInOneTile()
{
//    std::vector<Mole*> oneLocationMoles;
    for(int i = 0; i < moles.size(); ++i)
    {
        if(moles[i]->isUnderGround())
        {
            for(int j = i + 1; j < moles.size(); ++j)
            {
                if(moles[j]->isUnderGround())
                {
                    if(moles[i]->getLocation()->operator==(moles[j]->getLocation())
                       && moles[i]->getGender() != moles[j]->getGender())
                    {
//                        oneLocationMoles.push_back(moles[i]);
//                        oneLocationMoles.push_back(moles[j]);
                        moles[i]->setStatus(Rest);
                        moles[j]->setStatus(Rest);
                    }
                }
            }
        }
    }
//    if(oneLocationMoles.size() > 0)
//    {
//        for(int i = 0; i < oneLocationMoles.size(); ++i)
//        {
//            createNewMole(oneLocationMoles[i]->getLocation());
//            oneLocationMoles[i]->setStatus(MoleStatus::Rest);
//            oneLocationMoles[i + 1]->setStatus(MoleStatus::Rest);
//            oneLocationMoles.erase(oneLocationMoles.begin() + i);
//            oneLocationMoles.erase(oneLocationMoles.begin() + i);
//            i--;
//        }
//    }
}

void Game::createNewMole(Vector2 *location)
{
    int gender = randomer->random(2);
    if(gender == 2)
    {
        moles.push_back(new Mole(MoleGender::Female, new Vector2(location->getX(), location->getY()), this));
    }
    else
    {
        moles.push_back(new Mole(MoleGender::Male, new Vector2(location->getX(), location->getY()), this));
    }
}

void Game::killMole(Vector2 *location)
{
    for(int i = 0; i < moles.size(); ++i)
    {
        if(moles[i]->getLocation()->operator==(location))
        {
            delete moles[i];
            moles.erase(moles.begin() + i);
            break;
        }
    }
}
