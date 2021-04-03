#pragma once
#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Character {
	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	Character* Character_PTR;
	std::string sprite;
	bool isPrepared;

public:

	Character();											// Default constructor

	Character(std::string name);							// New character

	Character(json j);

	virtual json jsonify();

	virtual void setHealth(int health_reduction);

	virtual int getHealth();

	virtual int getAttack();

	virtual int getDefence();

	virtual int getSpeed();

	virtual std::string getSprite();

	virtual std::string getName();
};


class spoon : public Character {

	std::string name;
	int current_health;
	int max_health = 10;
	int attack = 5;
	int defence = 10;
	int speed = 4;
	std::string sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	spoon();												// Default constructor
	spoon(std::string name);								// New spoon character
	json jsonify();
};

class fork : public Character {

	std::string name;
	int current_health;
	int max_health = 7;
	int attack = 7;
	int defence = 5;
	int speed = 10;
	std::string sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	fork();												// Default constructor
	fork(std::string name);								// New fork character
	json jsonify();
};


class knife : public Character {

	std::string name;
	int current_health;
	int max_health = 5;
	int attack = 10;
	int defence = 2;
	int speed = 8;
	std::string sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	knife();												// Default constructor
	knife(std::string name);								// New knife character
	json jsonify();
};