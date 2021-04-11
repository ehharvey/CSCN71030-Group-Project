#ifndef CHARACTER_H
#define CHARACTER_H

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
	std::string fight_sprite;
	std::string dead_sprite;
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

	virtual std::string getFightSprite();

	virtual std::string getDeadSprite();

	virtual std::string getName();

	virtual bool getPrepared();

	virtual bool setPrepared(bool);

};


class spoon : public Character {

	std::string name;
	int current_health;
	int max_health = 10;
	int attack = 5;
	int defence = 10;
	int speed = 4;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	spoon();
	spoon(std::string name);								// New spoon character
	json jsonify();

	virtual void setHealth(int health_reduction) override;
	virtual int getHealth() override;
	virtual int getAttack() override;
	virtual int getDefence() override;
	virtual int getSpeed() override;
	virtual std::string getSprite() override;
	virtual std::string getFightSprite() override;
	virtual std::string getDeadSprite() override;
	virtual std::string getName() override;
	virtual bool getPrepared() override;
	virtual bool setPrepared(bool) override;

};

class fork : public Character {

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
	fork();
	fork(std::string name);								// New fork character
	json jsonify();
	virtual void setHealth(int health_reduction) override;
	virtual int getHealth() override;
	virtual int getAttack() override;
	virtual int getDefence() override;
	virtual int getSpeed() override;
	virtual std::string getSprite() override;
	virtual std::string getFightSprite() override;
	virtual std::string getDeadSprite() override;
	virtual std::string getName() override;
	virtual bool getPrepared() override;
	virtual bool setPrepared(bool) override;
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
	knife();
	knife(std::string name);								// New knife character
	json jsonify();
	virtual void setHealth(int health_reduction) override;
	virtual int getHealth() override;
	virtual int getAttack() override;
	virtual int getDefence() override;
	virtual int getSpeed() override;
	virtual std::string getSprite() override;
	virtual std::string getFightSprite() override;
	virtual std::string getDeadSprite() override;
	virtual std::string getName() override;
	virtual bool getPrepared() override;
	virtual bool setPrepared(bool) override;
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

#endif  // !CHARACTER_H