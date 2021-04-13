#ifndef UI_H
#define UI_H

// ANSI Colours
#define BLUE_FG 34
#define CYAN_FG 36
#define GREEN_FG 32
#define YELLOW_FG 33
#define BRIGHT_RED_FG 31
#define GREY_FG 90
#define LIGHT_RED_FG 91
#define BRIGHT_GREEN_FG 92
#define BRIGHT_BLUE_FG 94
#define BRIGHT_MAGENTA_FG 95
#define BRIGHT_CYAN_FG 96
#define DEFAULT_FG 0

enum input_choice { new_character, load_game,			// New game, load game
					new_spoon, new_fork, new_knife,		// Type of character
					attack, prepare, dodge,				// Combat options
					save, no_save, 						// Saving options
					carry_on, quit };					// To quit or not

#pragma once
#include "Character.h"

class UI {
	std::string User_character_Sprite;
	std::string Enemy_Sprite;

public:
	
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
	void gameWin();

	//Enemy output
	void enemyDodge();
	void enemyNotPrepared();
	void enemyAttackHit();		// maybe pass value of how many points removed from HP

	// User output
	void notPrepared();
	void userDodged();
	void dodgeFail();
	void attackHit();

	int getSaveInput();
	void displaySaveEntry(std::string character_name, int num);
	void displayCarryOn();
	
	void displayBattleIntro(Character* main_character, Character* enemy);
	void displayBattleTurn(Character* main_character, Character* enemy);
	void displayBattleChoices();
	void displayNotPrepared();

	void displayWelcome();
	void displayMenu();
	void displayPickClass();
	void displayNamePrompt();
	std::string getCharacterName();
	
	
	void displaySavePrompt();
};

#endif // !UI_H