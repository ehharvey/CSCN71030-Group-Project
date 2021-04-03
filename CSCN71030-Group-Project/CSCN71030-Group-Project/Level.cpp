#include "Level.h"
#include "Stubs.h"

Level::Level() {

}
Level::Level(Character* player, Character* enemy, enum stageType type ) {

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
	//combatOptions userInput;
	int turn = 0;
	while (!levelInfo->getPlayer()->getHealth() && !levelInfo->getEnemy()->getHealth()) {

		
		int userInput = someUIObject.get_input();

		switch (userInput)
		{
		case Attack:
			//if (levelInfo->getPlayer()->isPrepared())
			{
				if (simEnemyCombat(turn) == Prepare) {
					//both players prep
				}
				else if (simEnemyCombat(turn) == Dodge) {
					//enemy dodges player's attack
				}
				else if (simEnemyCombat(turn) == Attack) {
					//both players attack
				}
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
			}
			break;
		default:
			break;
		}
		turn++;

	}
}

combatOptions Level::simEnemyCombat(int turn) {
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
		break;
	}
}
Level::~Level() {

}