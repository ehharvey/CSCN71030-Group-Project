#pragma once
#include "Character.h"

class UI {
	std::string User_character_Sprite;
	std::string Enemy_Sprite;

public:
	//void new_event(Character* character_ptr, Character* enemy_ptr, event_type); // event type should be from game logic but I'm not sure what the form of it is yet
	void new_turn();
	int get_input();
	void get_sprite(Character* character_ptr);
	void get_sprite(Character* character_ptr, Character* enemy_ptr);

};