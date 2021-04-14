#include <random>
#include "RNG.h"

#define MOB_TOLERANCE 2

EnemyMobValues::EnemyMobValues(int user_max_health, int user_attack, int user_defence, int user_speed)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(MOB_TOLERANCE * -1, MOB_TOLERANCE);

	this->max_health = user_max_health + distribution(gen);
	this->attack = user_attack + distribution(gen);
	this->defence = user_defence + distribution(gen);
	this->speed = user_speed + distribution(gen);
}

BossValues::BossValues(int user_max_health, int user_attack, int user_defence, int user_speed)
	: EnemyMobValues(user_max_health, user_attack, user_defence, user_speed)
{
	this->max_health <<= 1;

	if (this->max_health < 0)
	{
		this->max_health *= -1;
	}
}
