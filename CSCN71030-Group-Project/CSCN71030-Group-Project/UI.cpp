#include "UI.h"
#include <iostream>

void UI::new_turn()
{
}

input_choice UI::get_input()
{
	unsigned char user_input;
	std::cin >> user_input;
	return (input_choice)user_input; // Seems brittle
}

void UI::display_Game_Over(Character* character_ptr)
{
	std::cout << character_ptr->getDeadSprite() << std::endl;

}

void UI::display_enemy_defeated(Character* enemy_ptr)
{
	std::cout << enemy_ptr->getDeadSprite() << std::endl;
	std::cout << "Congrats! You have defeated " << enemy_ptr->getName() << std::endl;
}

void UI::get_sprite(Character* character_ptr)
{
	std::cout << character_ptr->getSprite() << std::endl;
}

void UI::get_sprite(Character* character_ptr, Character* enemy_ptr)
{
	std::cout << enemy_ptr->getSprite() << std::endl;
	std::cout << character_ptr->getFightSprite() << std::endl;
}


void UI::display_menu()
{


}

void UI::initial_menu()
{


}

void UI::user_options()
{


}

void UI::game_opening()
{
}


// Emil:
void UI::displayBattleIntro(Character* main_character, Character* enemy)
{
	std::cout << main_character->getFightSprite() << std::endl;
	std::cout << enemy->getFightSprite() << std::endl;
}

void UI::displayBattleTurn(Character* main_character, Character* enemy) 
{
	std::cout << " You have: " << main_character->getHealth() << "/" << main_character->getMaxHealth() << " HP" << std::endl;
	std::cout << "Enemy has: " << enemy->getHealth() << "/" << enemy->getMaxHealth() << " HP" << std::endl;
}

void UI::displayWelcome() {
	std::cout << "Welcome to our game!" << std::endl;
}

void UI::displayMenu() 
{
	std::cout << "Please choose from the following options:" 	<< std::endl
	<<	input_choice::new_character 	<< ") New Character" 	<< std::endl
	<<  input_choice::load_game			<< ") Load Game" 		<< std::endl;
}

void UI::displayGameOver(Character* main_character) 
{
	std::cout << main_character->getDeadSprite() << std::endl
	<< "You have died" << std::endl;
}

void UI::displayEnemyDeath(Character* enemy) 
{
	std::cout << enemy->getDeadSprite() << std::endl
	<< "You defeated!" << std::endl;
}

void UI::displaySavePrompt() 
{
	std::cout << "Do you want to save?" 			<< std::endl
	<< input_choice::save		<< ") Save" 		<< std::endl
	<< input_choice::no_save	<< ") Don't Save" 	<< std::endl;
}

void UI::displayCarryOn() 
{
	std::cout << "Do you want to continue playing?" << std::endl
	<< input_choice::carry_on 	<< ") Continue" 	<< std::endl 
	<< input_choice::quit 		<< ") Quit"			<< std::endl;
}
