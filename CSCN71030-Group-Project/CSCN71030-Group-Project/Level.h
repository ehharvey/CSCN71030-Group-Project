#pragma once
#include "Character.h"
#include "RNG.h"
#include "UI.h"

enum stageType { Drawer = 0, DrawerEnd = 1,
				 Sink = 2, SinkEnd = 3,
				 Oven = 4, OvenEnd = 5,
				 Counter = 6, CounterEnd = 7 };
enum combatOptions {Attack, Dodge, Prepare};
enum combatStatus { Win, Die, InProgress };

class Level {
	Character* playerCharacter;	//references to both player and enemy characters
	Character* enemyCharacter;
	stageType type;


public:
	Level();
	~Level();
	Level(Character* player, Character* enemy, stageType type);

	Level(Character* player, stageType type);
	
	Character* getPlayer();
	Character* getEnemy();

	int simEnemyCombat(int turn);
	void calculateDamage(Character* attacker, Character* defender);
	int enterCombat(Level* currentLevel);

	input_choice getEnemyChoice(int turn);
	combatStatus enterCombat(void);
	combatStatus combatShouldContinue();
};
