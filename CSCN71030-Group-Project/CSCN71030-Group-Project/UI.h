#ifndef UI_H
#define UI_H

enum input_choice { new_character, load_game,
					new_spoon, new_fork, new_knife };


#pragma once
#include "Character.h"

class UI {
	std::string User_character_Sprite;
	std::string Enemy_Sprite;

public:
	//void new_event(Character* character_ptr, Character* enemy_ptr, event_type); // event type should be from game logic but I'm not sure what the form of it is yet
	void new_turn();
	input_choice get_input();
	void display_Game_Over(Character* character_ptr);
	void display_enemy_defeated(Character* enemy_ptr);
	void get_sprite(Character* character_ptr);
	void get_sprite(Character* character_ptr, Character* enemy_ptr);
	void display_menu();		// requires context to be passed to it
	void initial_menu();
	void user_options();
	void game_opening();
};

#endif // !UI_H