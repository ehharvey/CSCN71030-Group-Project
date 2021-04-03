#pragma once
#include "Stubs.h"

enum stageType { Drawer, Sink, Oven, Counter };
enum combatOptions {Attack, Dodge, Prepare};
class Level {
	Character* playerCharacter;	//references to both player and enemy characters
	Character* enemyCharacter;
	Level* nextLevel;	//implemented in the form of a linked list
	Level* previousLevel;
	stageType type;
	UI someUIObject;

public:
	Level();
	~Level();
	Level(Character* player, Character* enemy, stageType type);
	
	Character* getPlayer();
	Character* getEnemy();
	stageType getStageType();
	combatOptions simEnemyCombat(int turn);
	void calculateDamage(Character* attacker, Character* defender);
	int enterCombat(Level* currentLevel);
};
