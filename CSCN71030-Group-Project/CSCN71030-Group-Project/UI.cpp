#include "UI.h"
#include <iostream>

void UI::new_turn()
{
}

int UI::get_input()
{
	return 0;
}

void UI::get_sprite(Character* character_ptr)
{
	std::cout << character_ptr->getSprite() << std::endl;
}

void UI::get_sprite(Character* character_ptr, Character* enemy_ptr)
{
	std::cout << enemy_ptr->getSprite() << std::endl;
	std::cout << character_ptr->getSprite() << std::endl;
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
