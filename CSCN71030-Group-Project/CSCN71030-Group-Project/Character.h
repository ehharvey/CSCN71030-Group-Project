#pragma once
#include <string>


class Character {
	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	Character* Character_PTR;

public:

	Character();											// Default constructor

	Character(std::string name);							// New character

	// Cpp has a built-in regex library; can use to represent
	//   Characters as a string (e.g., delimited string)
	//	Character(std::string restore); // Restore from saving

	virtual void setHealth(int health);

	virtual int getHealth();

	virtual int getAttack();

	virtual int getDefence();

	virtual int getSpeed();

	virtual std::string getName();

	//	virtual explicit operator std::string(); // To typecast a character to a string
};


class spoon : public Character {

	std::string name;
	int current_health;
	int max_health = 10;
	int attack = 5;
	int defence = 10;
	int speed = 4;

	Character* Character_PTR;

public:

	spoon();												// Default constructor

	spoon(std::string name);								// New spoon character

};

class fork : public Character {

	std::string name;
	int current_health;
	int max_health = 7;
	int attack = 7;
	int defence = 5;
	int speed = 10;
	Character* Character_PTR;

public:

	fork();												// Default constructor
	fork(std::string name);								// New fork character

};


class knife : public Character {

	std::string name;
	int current_health;
	int max_health = 5;
	int attack = 10;
	int defence = 2;
	int speed = 8;

	Character* Character_PTR;

public:

	knife();												// Default constructor
	knife(std::string name);								// New knife character
};