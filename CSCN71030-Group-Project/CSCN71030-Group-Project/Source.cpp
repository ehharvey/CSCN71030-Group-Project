

#include "UI.h"
#include "Level.h"
#include "Object.h"
#include "ReadWrite.h"
#include "RNG.h"
#include "Character.h"


int main() {
	int userinput = 0;
	UI* ui = new UI();
	ui->game_opening();
	ui->initial_menu();
	userinput = ui->get_input();

	if (userinput == 1) {		// New game

		//get name from user
		std::string char_name = "Name";

		// get class selection from user
		userinput = ui->get_input();
		// if statements for class
		if (userinput == 1) {
			Character* UserChar = new spoon(char_name);
		}
		else if (userinput == 2) {
			Character* UserChar = new fork(char_name);
		}
		else {
			Character* UserChar = new knife(char_name);
		}

	}
	else if (userinput == 2) {	// Load game

		//load game

	}
	else {						// Exit

		return 0;
	}
	// switch case and while loop for game



	// Character Module Test case
		// User character
		Character* UserChar = new spoon("name");
		Character* UserChar2 = new fork("name");
		Character* UserChar3 = new knife("name");

		// Setters
		UserChar->setHealth(2); // -2 health scenario
		UserChar2->setHealth(2);
		UserChar3->setHealth(2);

		UserChar->setPrepared(true);	// Set as true
		UserChar2->setPrepared(true);	// Set as true
		UserChar3->setPrepared(true);	// Set as true

		// Getters
		UserChar->getHealth();	// Expected: 8
		UserChar2->getHealth();	// Expected: 5
		UserChar3->getHealth();	// Expected: 3

		UserChar->getPrepared();	// Expected: True
		UserChar2->getPrepared();	// Expected: True
		UserChar3->getPrepared();	// Expected: True

		UserChar->getAttack();	// Expected: 5
		UserChar2->getAttack();	// Expected: 7
		UserChar3->getAttack();	// Expected: 10

		UserChar->getDefence();	 // Expected: 10
		UserChar2->getDefence(); // Expected: 5
		UserChar3->getDefence(); // Expected: 2

		UserChar->getSpeed();	// Expected: 4
		UserChar2->getSpeed();	// Expected: 10
		UserChar3->getSpeed();	// Expected: 8

		UserChar->getName();	// Expected: name
		UserChar2->getName();	// Expected: name
		UserChar3->getName();	// Expected: name

		UserChar->getSprite();	// Expected: Spoon sprite
		UserChar2->getSprite();	// Expected: Fork sprite
		UserChar3->getSprite();	// Expected: Knife sprite

		UserChar->getFightSprite();		// Expected: Spoon fight sprite
		UserChar2->getFightSprite();	// Expected: Fork fight sprite
		UserChar3->getFightSprite();	// Expected: Knife fight sprite

		UserChar->getDeadSprite();	// Expected: Spoon dead sprite
		UserChar2->getDeadSprite();	// Expected: Fork dead sprite
		UserChar3->getDeadSprite();	// Expected: Knife dead sprite

		// Enemy & Boss Characters
		Character* EnemyChar = new DrawerEnemy(1, 1, 1, 1);		// Arbitrary values
		Character* EnemyChar2 = new DrawerBoss(1, 1, 1, 1);		// Arbitrary values
		Character* EnemyChar3 = new SinkEnemy(1, 1, 1, 1);		// Arbitrary values
		Character* EnemyChar4 = new SinkBoss(1, 1, 1, 1);		// Arbitrary values
		Character* EnemyChar5 = new OvenEnemy(1, 1, 1, 1);		// Arbitrary values
		Character* EnemyChar6 = new OvenBoss(1, 1, 1, 1);		// Arbitrary values
		Character* EnemyChar7 = new CounterEnemy(1, 1, 1, 1);	// Arbitrary values
		Character* EnemyChar8 = new CounterBoss(1, 1, 1, 1);	// Arbitrary values
		Character* EnemyChar9 = new FinalBoss(1, 1, 1, 1);		// Arbitrary values

		// Setters
		EnemyChar->setHealth(1);	// subtract 1 from health
		EnemyChar2->setHealth(1);	// subtract 1 from health
		EnemyChar3->setHealth(1);	// subtract 1 from health
		EnemyChar4->setHealth(1);	// subtract 1 from health
		EnemyChar5->setHealth(1);	// subtract 1 from health
		EnemyChar6->setHealth(1);	// subtract 1 from health
		EnemyChar7->setHealth(1);	// subtract 1 from health
		EnemyChar8->setHealth(1);	// subtract 1 from health
		EnemyChar9->setHealth(1);	// subtract 1 from health

		EnemyChar->setPrepared(true); // Set to prepared
		EnemyChar2->setPrepared(true); // Set to prepared
		EnemyChar3->setPrepared(true); // Set to prepared
		EnemyChar4->setPrepared(true); // Set to prepared
		EnemyChar5->setPrepared(true); // Set to prepared
		EnemyChar6->setPrepared(true); // Set to prepared
		EnemyChar7->setPrepared(true); // Set to prepared
		EnemyChar8->setPrepared(true); // Set to prepared
		EnemyChar9->setPrepared(true); // Set to prepared

		// Getters
		EnemyChar->getHealth();		// Expected: 0
		EnemyChar2->getHealth();	// Expected: 0
		EnemyChar3->getHealth();	// Expected: 0
		EnemyChar4->getHealth();	// Expected: 0
		EnemyChar5->getHealth();	// Expected: 0
		EnemyChar6->getHealth();	// Expected: 0
		EnemyChar7->getHealth();	// Expected: 0
		EnemyChar8->getHealth();	// Expected: 0
		EnemyChar9->getHealth();	// Expected: 0

		EnemyChar->getPrepared();	// Expected: True
		EnemyChar2->getPrepared();	// Expected: True
		EnemyChar3->getPrepared();	// Expected: True
		EnemyChar4->getPrepared();	// Expected: True
		EnemyChar5->getPrepared();	// Expected: True
		EnemyChar6->getPrepared();	// Expected: True
		EnemyChar7->getPrepared();	// Expected: True
		EnemyChar8->getPrepared();	// Expected: True
		EnemyChar9->getPrepared();	// Expected: True


		EnemyChar->getAttack();		// Expected: 1
		EnemyChar2->getAttack();	// Expected: 1
		EnemyChar3->getAttack();	// Expected: 1
		EnemyChar4->getAttack();	// Expected: 1
		EnemyChar5->getAttack();	// Expected: 1
		EnemyChar6->getAttack();	// Expected: 1
		EnemyChar7->getAttack();	// Expected: 1
		EnemyChar8->getAttack();	// Expected: 1
		EnemyChar9->getAttack();	// Expected: 1

		EnemyChar->getDefence();	// Expected: 1
		EnemyChar2->getDefence();	// Expected: 1
		EnemyChar3->getDefence();	// Expected: 1
		EnemyChar4->getDefence();	// Expected: 1
		EnemyChar5->getDefence();	// Expected: 1
		EnemyChar6->getDefence();	// Expected: 1
		EnemyChar7->getDefence();	// Expected: 1
		EnemyChar8->getDefence();	// Expected: 1
		EnemyChar9->getDefence();	// Expected: 1

		EnemyChar->getSpeed();		// Expected 1
		EnemyChar2->getSpeed();		// Expected 1
		EnemyChar3->getSpeed();		// Expected 1
		EnemyChar4->getSpeed();		// Expected 1
		EnemyChar5->getSpeed();		// Expected 1
		EnemyChar6->getSpeed();		// Expected 1
		EnemyChar7->getSpeed();		// Expected 1
		EnemyChar8->getSpeed();		// Expected 1
		EnemyChar9->getSpeed();		// Expected 1

		EnemyChar->getSprite();		
		EnemyChar2->getSprite();
		EnemyChar3->getSprite();
		EnemyChar4->getSprite();
		EnemyChar5->getSprite();
		EnemyChar6->getSprite();
		EnemyChar7->getSprite();
		EnemyChar8->getSprite();
		EnemyChar9->getSprite();

		EnemyChar->getDeadSprite();
		EnemyChar2->getDeadSprite();
		EnemyChar3->getDeadSprite();
		EnemyChar4->getDeadSprite();
		EnemyChar5->getDeadSprite();
		EnemyChar6->getDeadSprite();
		EnemyChar7->getDeadSprite();
		EnemyChar8->getDeadSprite();
		EnemyChar9->getDeadSprite();

}