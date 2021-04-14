#include <iostream>
#include "Level.h"


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
void Level::calculateDamage(Character* attacker, Character* defender) {			// Make this return an int with the value, so UI can output it 
	defender->setHealth(defender->getHealth() - attacker->getAttack()); //subtracts attack from health
	return;
}

Level::~Level() {
	delete enemyCharacter;
}





// Emil:

Level::Level(Character* player, stageType type)
{
	this->playerCharacter = player;
	this->type = type;

	switch (type)
	{
		case stageType::Drawer:
		{
			EnemyMobValues stats = EnemyMobValues();
			this->enemyCharacter = new DrawerEnemy(stats.max_health, 
												   stats.attack, 
												   stats.defence, 
												   stats.speed);
			break;
		}
		

		case stageType::DrawerEnd:
		{
			BossValues stats = BossValues();
			this->enemyCharacter = new DrawerBoss(stats.max_health, 
												  stats.attack, 
												  stats.defence, 
												  stats.speed);
			break;
		}

		case stageType::Sink:
		{
			EnemyMobValues stats = EnemyMobValues();
			this->enemyCharacter = new SinkEnemy(stats.max_health, 
												 stats.attack, 
												 stats.defence, 
												 stats.speed);
			break;
		}

		case stageType::SinkEnd:
		{
			BossValues stats = BossValues();;
			this->enemyCharacter = new SinkBoss(stats.max_health, 
												stats.attack, 
												stats.defence, 
												stats.speed);
			break;
		}

		case stageType::Oven:
		{
			EnemyMobValues stats = EnemyMobValues();
			this->enemyCharacter = new OvenEnemy(stats.max_health, 
												 stats.attack, 
												 stats.defence, 
												 stats.speed);
			break;
		}

		case stageType::OvenEnd:
		{
			BossValues stats = BossValues();
			this->enemyCharacter = new OvenBoss(stats.max_health, 
												stats.attack, 
												stats.defence, 
												stats.speed);
			break;
		}

		case stageType::Counter:
		{
			EnemyMobValues stats = EnemyMobValues();;
			this->enemyCharacter = new CounterEnemy(stats.max_health, 
													stats.attack, 
													stats.defence, 
													stats.speed);
			break;
		}

		case stageType::CounterEnd:
		{
			BossValues stats = BossValues();
			this->enemyCharacter = new CounterBoss(stats.max_health, 
												   stats.attack, 
												   stats.defence, 
												   stats.speed);
			break;
		}
	}
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
					ui->enemyDodge();
				}
				else {
					calculateDamage(this->getPlayer(), this->getEnemy());
					ui->attackHit();
				}
			} else {
				ui->notPrepared();			// Notify user that they were not prepared :( )
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
			ui->displayInvalidInput();
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
					ui->userDodged();
				}
				else {
					calculateDamage(this->getEnemy(), this->getPlayer());
					ui->enemyAttackHit();
				}
			} else {
				ui->enemyNotPrepared();
			}
			this->getEnemy()->setPrepared(false);
			ui->enemyPreparing();
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
		ui->display_enemy_defeated(getEnemy());
	}

	// Return based on combat results
	return combat_status;
}
