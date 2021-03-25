#pragma once

typedef struct character{};

class Level {
	character& playerCharacter;
	character& enemyCharacter;
public:
	Level();
	~Level();
	int getCombatResult();
	
};