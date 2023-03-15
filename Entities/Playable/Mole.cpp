
#include <ctime>
#include "Mole.h"



Mole::Mole(MoleGender gender, Vector2 *location, Game *game)
{
    this->gender = gender;
    this->location = location;
    this->game = game;
}

Mole::~Mole()
{
    delete location;
}

const MoleGender Mole::getGender() const
{
    return this->gender;
}

void Mole::setGender(MoleGender gender)
{
    this->gender = gender;
}

Vector2 *Mole::getLocation()
{
    return location;
}

void Mole::setLocation(Vector2 *location)
{
    this->location = location;
}

MoleStatus Mole::getStatus()
{
    return status;
}

void Mole::setStatus(MoleStatus status)
{
    this->status = status;
}

void Mole::execAction()
{
    if(this->status == MoleStatus::Rest)
    {
        if(gender == Female)
        {
            game->createNewMole(location);
        }
        status = MoleStatus::UnderGround;
    }
    else if(this->status == MoleStatus::UnderGround)
    {
        int var = game->getRandomer()->random(3);
        if(var == 0)
        {
            this->status = MoleStatus::OnTheGround;
        }
        else
        {
            move();
        }
        reProduct();
    }
    else if(this->status == MoleStatus::OnTheGround)
    {
        attack();
        this->status = MoleStatus::Attacked;
    }
    else if(this->status == MoleStatus::Attacked)
    {
       this->status = MoleStatus::UnderGround;
    }
}

void Mole::move()
{
    location = chooseTile();
}

void Mole::attack()
{
    if(game->getGameField()->tileIsAlive(*location))
    {
        game->getGameField()->kill(*location);
    }
    std::vector<Vector2*> tiles;
    getTilesAround(tiles);
    filterTiles(tiles);
    filterTilesForAttack(tiles);
    for(int i = 0; i < tiles.size(); ++i)
    {
        if(game->getRandomer()->random(2) == 0)
        {
            game->getGameField()->kill(*tiles[i]);
        }
    }
}

Vector2* Mole::chooseTile()
{
    std::vector<Vector2*> tiles;
    getTilesAround(tiles);
    filterTiles(tiles);
    return tiles[game->getRandomer()->random(tiles.size() - 1)];
}

void Mole::filterTiles(std::vector<Vector2 *> &tiles)
{
    for(int i = 0; i < tiles.size(); ++i)
    {
        if(tiles[i]->getX() < 0 || tiles[i]->getX() > game->getGameField()->getSize()->getX() - 1 ||
           tiles[i]->getY() < 0 || tiles[i]->getY() > game->getGameField()->getSize()->getY() - 1)
        {
            tiles.erase(tiles.begin() + i);
            i--;
        }
    }
}

void Mole::filterTilesForAttack(std::vector<Vector2 *> &tiles)
{
    for(int i = 0; i < tiles.size(); ++i)
    {
        if(!game->getGameField()->tileIsAlive(*tiles[i]))
        {
            tiles.erase(tiles.begin() + i);
            i--;
        }
    }
}

std::vector<Vector2*>& Mole::getTilesAround(std::vector<Vector2*> &tiles)
{
    tiles.push_back(new Vector2(location->getX() - 1, location->getY()));
    tiles.push_back(new Vector2(location->getX() + 1, location->getY()));
    tiles.push_back(new Vector2(location->getX(), location->getY() - 1));
    tiles.push_back(new Vector2(location->getX(), location->getY() + 1));
    return tiles;
}

void Mole::reProduct()
{
    if(gender == Female && status == UnderGround)
    {
        for(int i = 0; i < game->getMoles().size(); ++i)
        {
            if(this == game->getMoles()[i])
            {
                continue;
            }
            if(location->operator==(game->getMoles()[i]->location) && game->getMoles()[i]->isMan())
            {
                status = Rest;
                game->getMoles()[i]->setStatus(Rest);
            }
        }
    }
}

bool Mole::isUnderGround()
{
    return status == MoleStatus::UnderGround;
}

bool Mole::isOnTheGround()
{
    return status == MoleStatus::OnTheGround;
}

bool Mole::isAttacked()
{
    return status == MoleStatus::Attacked;
}

bool Mole::isMan()
{
    return gender == MoleGender::Male;
}

bool Mole::isWoman()
{
    return gender == MoleGender::Female;
}

bool Mole::isRest()
{
    return status == MoleStatus::Rest;
}




// entity