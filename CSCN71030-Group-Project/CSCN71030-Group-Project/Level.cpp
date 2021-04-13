#include <iostream>
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

input_choice Level::getEnemyChoice(int turn) {
	switch (turn%3)	//linear combat pattern
	{
	case 0:
		return prepare;//turn 1 prep
		break;
	case 1:
		return dodge;//turn 2 defend
		break;
	case 2:
		return attack;//turn 3 attack
		break;
	default:
		exit(EXIT_FAILURE); // Placeholder
		break;
	}
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
	delete enemyCharacter;
}







// Emil:

Level::Level(Character* player, stageType type)
{
	this->playerCharacter = playerCharacter;
	this->type = type;

	switch (type)
	{
		case stageType::Drawer:
		this->enemyCharacter = new DrawerEnemy(10, 10, 10, 10);
		break;

		case stageType::Sink:
		this->enemyCharacter = new SinkEnemy(10, 10, 10, 10);
		break;

		case stageType::Oven:
		this->enemyCharacter = new OvenEnemy(10, 10, 10, 10);
		break;

		case stageType::Counter:
		this->enemyCharacter = new CounterEnemy(10, 10, 10, 10);
	}
}

combatStatus Level::combatShouldContinue() {
	if (this->getPlayer()->getHealth() == 0)
	{
		return Die;
	}
	else if (this->getEnemy()->getHealth() == 0)
	{
		return Win;
	}
	else
	{
		return InProgress;
	}
}


combatStatus Level::enterCombat() {
	int userInput = 0;
	unsigned char turn = 0;

	UI* ui = new UI();

	ui->displayBattleIntro(getPlayer(), getEnemy());

	combatStatus combat_status;
	do {
		// Display turn information
		ui->displayBattleTurn(getPlayer(), getEnemy());

		// Decide enemy's turn
		input_choice enemy_choice = getEnemyChoice(turn);


		// Get/process user turn
		input_choice user_turn_choice;
		bool valid_user_turn;
		do {
			user_turn_choice = ui->get_input();

			switch (user_turn_choice) {

			case input_choice::attack:
			if (this->getPlayer()->getPrepared()) {
				if (enemy_choice == dodge) {
					std::cout << "Enemy dodged" << std::endl; // TODO
				}
				else {
					calculateDamage(this->getPlayer(), this->getEnemy());
				}
			} else {
				// Notify user that they were not prepared :( )
			}
			this->getPlayer()->setPrepared(false);
			valid_user_turn = true;
			break;


			case input_choice::dodge:
			// Don't do anything
			valid_user_turn = true;
			break;


			case input_choice::prepare:
			this->getPlayer()->setPrepared(true);
			valid_user_turn = true;
			break;


			default:
			valid_user_turn = false;
			break;

			}
		} while(!valid_user_turn);

		
		// User should be alive at this point
		// Check if  we should continue (has enemy died??)
		combat_status = combatShouldContinue();

		if (combat_status == InProgress)
		{
			// Process enemy turn
			switch (enemy_choice) {

			case input_choice::attack:
			if (this->getEnemy()->getPrepared()) {
				if (user_turn_choice == dodge) {
					std::cout << "You dodged an attack" << std::endl; // TODO
				}
				else {
					calculateDamage(this->getEnemy(), this->getPlayer());
				}
			} else {
				std::cout << "Enemy wasn't prepared" << std::endl; // TODO
			}
			this->getEnemy()->setPrepared(false);
			valid_user_turn = true;
			break;


			case input_choice::dodge:
			// Don't do anything
			break;


			case input_choice::prepare:
			this->getEnemy()->setPrepared(true);
			break;

			
			default:
			exit(EXIT_FAILURE); // Placeholder crash
			}
		}
		

		// Process result of turn
		combat_status = combatShouldContinue();
		turn++;
	} while(combat_status == InProgress);

	delete ui;
	
	// Temporary
	if (combat_status == Win) {
		ui->displayEnemyDeath(getEnemy());
	}

	// Return based on combat results
	return combat_status;
}

