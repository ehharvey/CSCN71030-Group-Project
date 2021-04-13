#include <iostream>
#include "Level.h"

Level::Level(Character* player, stageType type)
{
	this->playerCharacter = player;
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

Character* Level::getPlayer() {
	return this->playerCharacter;
}
Character* Level::getEnemy() {
	return this->enemyCharacter;
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

void Level::calculateDamage(Character* attacker, Character* defender) {
	defender->setHealth(defender->getHealth() - attacker->getAttack()); //subtracts attack from health
	return;
}

combatStatus Level::combatShouldContinue() {
	if (this->getPlayer()->getHealth() <= 0)
	{
		return Die;
	}
	else if (this->getEnemy()->getHealth() <= 0)
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
			ui->displayBattleChoices();
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

Level::~Level() {
	delete enemyCharacter;
}

