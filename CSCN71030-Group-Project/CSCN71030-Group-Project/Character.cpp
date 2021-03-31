#include "Character.h"

Character::Character()
{
    this->attack = 0;
    this->current_health = 0;
    this->defence = 0;
    this->max_health = 0;
    this->speed = 0;
    this->name = " ";
}

Character::Character(std::string name)
{
    this->attack = 0;
    this->current_health = 0;
    this->defence = 0;
    this->max_health = 0;
    this->speed = 0;

    this->name = name;
    this->Character_PTR = this;


}

//Character::Character(std::string restore)
//{
//
//}

void Character::setHealth(int health)
{
    this->current_health = health;
}

int Character::getHealth()
{
    return this->current_health;
}

int Character::getAttack()
{
    return this->attack;
}

int Character::getDefence()
{
    return this->defence;
}

int Character::getSpeed()
{
    return this->speed;
}

std::string Character::getName()
{
    return this->name;
}

//Character::operator std::string()
//{
//}

spoon::spoon()
{
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->name = " ";
}

spoon::spoon(std::string name)
{
    this->name = name;
}

fork::fork()
{
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->name = " ";
}

fork::fork(std::string name)
{
    this->name = name;
}

knife::knife()
{
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->name = " ";
}

knife::knife(std::string name)
{
    this->name = name;
}
