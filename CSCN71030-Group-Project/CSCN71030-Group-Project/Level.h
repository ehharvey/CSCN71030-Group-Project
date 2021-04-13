#ifndef LEVEL_H
#define LEVEL_H

#pragma once
#include "Character.h"

enum stageType { Drawer = 0, Sink = 1, Oven = 2, Counter = 3 };
enum combatOptions {Attack, Dodge, Prepare};
class Level {
	Character* playerCharacter;	//references to both player and enemy characters
	Character* enemyCharacter;
	stageType type;


public:
	Level();
	~Level();
	Level(Character* player, Character* enemy, stageType type);
	
	Character* getPlayer();
	Character* getEnemy();
	stageType getStageType();
	int simEnemyCombat(int turn);
	void calculateDamage(Character* attacker, Character* defender);
	int enterCombat(Level* currentLevel);
};

#endif // !LEVEL_H