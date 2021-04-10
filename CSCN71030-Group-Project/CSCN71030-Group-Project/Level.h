#pragma once
#include "Character.h"


enum stageType { Drawer, Sink, Oven, Counter };
enum combatOptions {Attack, Dodge, Prepare};


class Level {
	// Emil: Consider making this references and not pointers
	Character* playerCharacter;	//references to both player and enemy characters
	Character* enemyCharacter;
	stageType type;


public:
	Level(); // Emil: This is unneeded; don't have a default constructor unless
			 //    it is useful
	~Level(); // Emil: This is unnecessary since Level isn't creating anything
			  //    on the heap
	
	// Emil: Shouldn't Level create its own enemy?
	// Also see above
	Level(Character* player, Character* enemy, stageType type);
	
	// Emil: I'm not sure if these getters are necessary or should be public
	Character* getPlayer();
	Character* getEnemy();
	stageType getStageType();

	// Emil: These functions may also be unnecessary
	int simEnemyCombat(int turn);
	void calculateDamage(Character* attacker, Character* defender);

	// Emil: I'm not sure why this parameter is necessary. It seems
	//    to be just a pointer to itself
	int enterCombat(Level* currentLevel);
};
