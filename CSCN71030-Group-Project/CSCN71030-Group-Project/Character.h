#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once
#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Character {
protected:
	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;
	bool isPrepared;

public:
	Character(std::string name); // New character

	Character(json j);

	virtual json jsonify();

	void setHealth(int health_reduction);

	int getHealth();

	int getMaxHealth();

	int getAttack();

	int getDefence();

	int getSpeed();

	std::string getSprite();

	std::string getFightSprite();

	std::string getDeadSprite();

	std::string getName();

	bool getPrepared();

	bool setPrepared(bool);

};

class spoon : public Character {
public:
	spoon(std::string name); // New spoon character
	json jsonify();
};

class fork : public Character {
public:
	fork(std::string name); // New fork character
	json jsonify();
};


class knife : public Character {
public: 
	knife(std::string name); // New knife character
	json jsonify();
};

class DrawerEnemy : public Character {
public:
	DrawerEnemy(int max_health, int attack, int defence, int speed); // Constructor
};

class DrawerBoss : public Character {
public:
	DrawerBoss(int max_health, int attack, int defence, int speed); // Constructor
};

class SinkEnemy : public Character {
public:
	SinkEnemy(int max_health, int attack, int defence, int speed); // Constructor
};

class SinkBoss : public Character {
public:
	SinkBoss(int max_health, int attack, int defence, int speed); // Constructor
};

class OvenEnemy : public Character {
public:
	OvenEnemy(int max_health, int attack, int defence, int speed); // Constructor
};

class OvenBoss : public Character {
public:
	OvenBoss(int max_health, int attack, int defence, int speed); // Constructor
};

class CounterEnemy : public Character {
public:
	CounterEnemy(int max_health, int attack, int defence, int speed); // Constructor
};

class CounterBoss : public Character {
public:
	CounterBoss(int max_health, int attack, int defence, int speed); // Constructor
};

class FinalBoss : public Character {
public:
	FinalBoss(int max_health, int attack, int defence, int speed); // Constructor
};

#endif  // !CHARACTER_H