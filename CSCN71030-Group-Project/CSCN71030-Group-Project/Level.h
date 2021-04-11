#pragma once
#include "Character.h"

enum stageType { Drawer, Sink, Oven, Counter };
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
