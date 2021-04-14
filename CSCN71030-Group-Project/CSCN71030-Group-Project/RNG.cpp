#include <random>
#include "RNG.h"

#define MOB_TOLERANCE 2

EnemyMobValues::EnemyMobValues()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(MOB_TOLERANCE * -1, MOB_TOLERANCE);

	this->max_health = 15 + distribution(gen);
	this->attack = 4 + distribution(gen);
	this->defence = 3 + distribution(gen);
	this->speed = 5 + distribution(gen);
}

BossValues::BossValues()
	: EnemyMobValues()
{
	this->max_health <<= 1;

	if (this->max_health < 0)
	{
		this->max_health *= -1;
	}
}
