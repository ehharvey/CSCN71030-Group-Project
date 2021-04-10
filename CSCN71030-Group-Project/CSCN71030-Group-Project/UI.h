#pragma once
#include "Character.h"

// Emil: Consider having separate classes for UI input relating to 
//    file selection, combat, and saving. I think this should be split up
// Unless There is any data that relates to UI state, I think we may
//    be better not having classes, but just functions

class UI {
	std::string User_character_Sprite;
	std::string Enemy_Sprite;

public:
	//void new_event(Character* character_ptr, Character* enemy_ptr, event_type); // event type should be from game logic but I'm not sure what the form of it is yet
	void new_turn(); // Emil: I think this is unnecessary now
	int get_input(); // Emil: I think this should be renamed for clarity
	void display_Game_Over(Character* character_ptr);
	void display_enemy_defeated(Character* enemy_ptr);

	// Emil: I don't know why this function is needed
	//    also "get" is a little misleading; maybe "print" would be a better choice
	void get_sprite(Character* character_ptr); 
	void get_sprite(Character* character_ptr, Character* enemy_ptr);
	void display_menu();		// requires context to be passed to it
	void initial_menu();
	void user_options();
	void game_opening();
};


// Emil: I think this functionality is also needed
//    Get user to choose between creating a new character or loading
//    Display available slots to the user
//    Get user input about slot to load
//    Display combat turn
//    Get user choice for combat turn
//    Display result of combat turn
//    Get user choice about whether to save or not (this is optional)