 
#pragma once
#include "Character.h"
#include "UI.h"

enum stageType { Drawer = 0, Sink = 1, Oven = 2, Counter = 3 };
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
@ -23,6 +27,10 @@ public:
	int simEnemyCombat(int turn);
	void calculateDamage(Character* attacker, Character* defender);
	int enterCombat(Level* currentLevel);

	input_choice getEnemyChoice(int turn);
	combatStatus enterCombat(void);
	combatStatus combatShouldContinue();
};

#endif // !LEVEL_H