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
	Character* Character_PTR; // Emil: Unecessary
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;
	bool isPrepared;

public:

	// Emil: We don't need a default constructor
	Character();											// Default constructor

	Character(std::string name);							// New character

	Character(json j);

	virtual json jsonify();

	// Emil: These functions should not be virtual
	virtual void setHealth(int health_reduction);
	virtual int getHealth();
	virtual int getAttack();
	virtual int getDefence();
	virtual int getSpeed();
	virtual std::string getSprite();
	virtual std::string getFightSprite();
	virtual std::string getDeadSprite();
	virtual std::string getName();
	virtual bool getPrepared();
	virtual bool setPrepared(bool);

};


class spoon : public Character {

	// Emil: No need to duplicate private members of the super class
	//    Consider making the private members of the super class protected instead
	std::string name;
	int current_health;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;
	Character* Character_PTR;
	bool isPrepared;

	// Emil: Default values could be considered more behavioural; maybe put this
	//    in the source?
	int max_health = 10;
	int attack = 5;
	int defence = 10;
	int speed = 4;
	
public:
	// Emil: No default constructor is needed
	spoon();												// Default constructor
	spoon(std::string name);								// New spoon character
	json jsonify();
};

class fork : public Character {
	// Emil: See above
	std::string name;
	int current_health;
	int max_health = 7;
	int attack = 7;
	int defence = 5;
	int speed = 10;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;

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
	std::string fight_sprite;
	std::string dead_sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	knife();												// Default constructor
	knife(std::string name);								// New knife character
	json jsonify();
};

class DrawerEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	// Emil: What do these ints refer to?
	//    maybe we should have a structure representing the values needed
	// e.g., struct enemy_stats
	DrawerEnemy(int, int, int, int);												// Constructor
};

class DrawerBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	DrawerBoss(int, int, int, int);												// Constructor
};

class SinkEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	SinkEnemy(int, int, int, int);												// Constructor
};

class SinkBoss : public Character {
	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	SinkBoss(int, int, int, int);												// Constructor
};

class OvenEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	OvenEnemy(int, int, int, int);												// Constructor
};
class OvenBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	OvenBoss(int, int, int, int);												// Constructor
};
class CounterEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	CounterEnemy(int, int, int, int);												// Constructor
};
class CounterBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	CounterBoss(int, int, int, int);												// Constructor
};

class FinalBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	FinalBoss(int, int, int, int);												// Constructor
};