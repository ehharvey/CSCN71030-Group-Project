#include "UI.h"
#include <iostream>

void UI::new_turn()
{
}

int UI::get_input()
{
	return 0;
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
