#pragma once
#include <string>

// Character
class Character {
	std::string name;
	
	int health;
	
	int attack;
	
public:
	Character(std::string name); // New character
	Character(std::string restore); // Restore from saving

	void setHealth(int health);
	
	int getAttack();

	explicit operator std::string();
};