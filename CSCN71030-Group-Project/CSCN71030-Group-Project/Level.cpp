#include "Level.h"
//#include "Stubs.h"


Level::Level() {
	this->playerCharacter = NULL;
	this->enemyCharacter = NULL;
	this->type = Drawer;
}
Level::Level(Character* player, Character* enemy, stageType type ) {
	this->playerCharacter = player;
	this->enemyCharacter = enemy;
	this->type = type;
}
Character* Level::getPlayer() {
	return this->playerCharacter;
}
Character* Level::getEnemy() {
	return this->enemyCharacter;
}
stageType Level::getStageType() {
	return this->type;
}

int Level::enterCombat(Level* levelInfo) {
	int userInput = 0;
	int turn = 0;
	while (!levelInfo->getPlayer()->getHealth() && !levelInfo->getEnemy()->getHealth()) {

		
		

		switch (userInput)
		{
		case Attack:
			//if (levelInfo->getPlayer()->isPrepared())
			{
				if (simEnemyCombat(turn) == Prepare) {
					//Player attacks while enemy preps
					calculateDamage(levelInfo->getPlayer(), levelInfo->getEnemy());
				}
				else if (simEnemyCombat(turn) == Dodge) {
					//enemy dodges player's attack
				}
				else if (simEnemyCombat(turn) == Attack) {
					//both players attack
					calculateDamage(levelInfo->getPlayer(), levelInfo->getEnemy());
					calculateDamage(levelInfo->getEnemy(), levelInfo->getPlayer());
				}
			}
			//else
			{
				//ui
			}
			break;
		case Dodge:
			if (simEnemyCombat(turn) == Prepare) {
				//player dodges, enemy preps
			}
			else if (simEnemyCombat(turn) == Dodge) {
				//both players dodge
			}
			else if (simEnemyCombat(turn) == Attack) {
				//enemy attacks, player dodges
			}
			break;
		case Prepare:
			//levelInfo->getPlayer()->isPrepared();
			if (simEnemyCombat(turn) == Prepare) {
				//both players prep
				//levelInfo->getEnemy()->isPrepared();
			}
			else if (simEnemyCombat(turn) == Dodge) {
				//player preps, enemy dodges
			}
			else if (simEnemyCombat(turn) == Attack) {
				//player preps, enemy attacks
				calculateDamage(levelInfo->getEnemy(), levelInfo->getPlayer());
			}
			break;
		default:
			break;
		}
		turn++;

	}
	return 0;
}

int Level::simEnemyCombat(int turn) {
	switch (turn%3)	//linear combat pattern
	{
	case 0:
		return Prepare;//turn 1 prep
		break;
	case 1:
		return Dodge;//turn 2 defend
		break;
	case 2:
		return Attack;//turn 3 attack
		break;
	default:
		return Dodge;
		break;
	}
}
void Level::calculateDamage(Character* attacker, Character* defender) {
	defender->setHealth(defender->getHealth() - attacker->getAttack()); //subtracts attack from health
	return;
}
Level::~Level() {

}