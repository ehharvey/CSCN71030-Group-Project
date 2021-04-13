#include "UI.h"
#include <iostream>
#include <string>
#include <windows.h>

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

void UI::game_opening() {

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //store current dimensions
	MoveWindow(console, 0, 0, 1600, 1000, TRUE); // 1600 width, 1000 height

	std::string GameOpening = R"(
          _____                    _____                _____                    _____                _____                    _____            _____                    _____          
         /\    \                  /\    \              /\    \                  /\    \              /\    \                  /\    \          /\    \                  /\    \         
        /::\____\                /::\____\            /::\    \                /::\    \            /::\    \                /::\____\        /::\    \                /::\    \        
       /:::/    /               /::::|   |            \:::\    \               \:::\    \           \:::\    \              /:::/    /       /::::\    \              /::::\    \       
      /:::/    /               /:::::|   |             \:::\    \               \:::\    \           \:::\    \            /:::/    /       /::::::\    \            /::::::\    \      
     /:::/    /               /::::::|   |              \:::\    \               \:::\    \           \:::\    \          /:::/    /       /:::/\:::\    \          /:::/\:::\    \     
    /:::/    /               /:::/|::|   |               \:::\    \               \:::\    \           \:::\    \        /:::/    /       /:::/__\:::\    \        /:::/  \:::\    \    
   /:::/    /               /:::/ |::|   |               /::::\    \              /::::\    \          /::::\    \      /:::/    /       /::::\   \:::\    \      /:::/    \:::\    \   
  /:::/    /      _____    /:::/  |::|   | _____        /::::::\    \    ____    /::::::\    \        /::::::\    \    /:::/    /       /::::::\   \:::\    \    /:::/    / \:::\    \  
 /:::/____/      /\    \  /:::/   |::|   |/\    \      /:::/\:::\    \  /\   \  /:::/\:::\    \      /:::/\:::\    \  /:::/    /       /:::/\:::\   \:::\    \  /:::/    /   \:::\ ___\ 
|:::|    /      /::\____\/:: /    |::|   /::\____\    /:::/  \:::\____\/::\   \/:::/  \:::\____\    /:::/  \:::\____\/:::/____/       /:::/__\:::\   \:::\____\/:::/____/     \:::|    |
|:::|____\     /:::/    /\::/    /|::|  /:::/    /   /:::/    \::/    /\:::\  /:::/    \::/    /   /:::/    \::/    /\:::\    \       \:::\   \:::\   \::/    /\:::\    \     /:::|____|
 \:::\    \   /:::/    /  \/____/ |::| /:::/    /   /:::/    / \/____/  \:::\/:::/    / \/____/   /:::/    / \/____/  \:::\    \       \:::\   \:::\   \/____/  \:::\    \   /:::/    / 
  \:::\    \ /:::/    /           |::|/:::/    /   /:::/    /            \::::::/    /           /:::/    /            \:::\    \       \:::\   \:::\    \       \:::\    \ /:::/    /  
   \:::\    /:::/    /            |::::::/    /   /:::/    /              \::::/____/           /:::/    /              \:::\    \       \:::\   \:::\____\       \:::\    /:::/    /   
    \:::\__/:::/    /             |:::::/    /    \::/    /                \:::\    \           \::/    /                \:::\    \       \:::\   \::/    /        \:::\  /:::/    /    
     \::::::::/    /              |::::/    /      \/____/                  \:::\    \           \/____/                  \:::\    \       \:::\   \/____/          \:::\/:::/    /     
      \::::::/    /               /:::/    /                                 \:::\    \                                    \:::\    \       \:::\    \               \::::::/    /      
       \::::/    /               /:::/    /                                   \:::\____\                                    \:::\____\       \:::\____\               \::::/    /       
        \::/____/                \::/    /                                     \::/    /                                     \::/    /        \::/    /                \::/____/        
         ~~                       \/____/                                       \/____/                                       \/____/          \/____/                  ~~              
 

           _____                    _____                    _____                    _____          
         /\    \                  /\    \                  /\    \                  /\    \         
        /::\    \                /::\    \                /::\____\                /::\    \        
       /::::\    \              /::::\    \              /::::|   |               /::::\    \       
      /::::::\    \            /::::::\    \            /:::::|   |              /::::::\    \      
     /:::/\:::\    \          /:::/\:::\    \          /::::::|   |             /:::/\:::\    \     
    /:::/  \:::\    \        /:::/__\:::\    \        /:::/|::|   |            /:::/__\:::\    \    
   /:::/    \:::\    \      /::::\   \:::\    \      /:::/ |::|   |           /::::\   \:::\    \   
  /:::/    / \:::\    \    /::::::\   \:::\    \    /:::/  |::|___|______    /::::::\   \:::\    \  
 /:::/    /   \:::\ ___\  /:::/\:::\   \:::\    \  /:::/   |::::::::\    \  /:::/\:::\   \:::\    \ 
/:::/____/  ___\:::|    |/:::/  \:::\   \:::\____\/:::/    |:::::::::\____\/:::/__\:::\   \:::\____\
\:::\    \ /\  /:::|____|\::/    \:::\  /:::/    /\::/    / ~~~~~/:::/    /\:::\   \:::\   \::/    /
 \:::\    /::\ \::/    /  \/____/ \:::\/:::/    /  \/____/      /:::/    /  \:::\   \:::\   \/____/ 
  \:::\   \:::\ \/____/            \::::::/    /               /:::/    /    \:::\   \:::\    \     
   \:::\   \:::\____\               \::::/    /               /:::/    /      \:::\   \:::\____\    
    \:::\  /:::/    /               /:::/    /               /:::/    /        \:::\   \::/    /    
     \:::\/:::/    /               /:::/    /               /:::/    /          \:::\   \/____/     
      \::::::/    /               /:::/    /               /:::/    /            \:::\    \         
       \::::/    /               /:::/    /               /:::/    /              \:::\____\        
        \::/____/                \::/    /                \::/    /                \::/    /        
                                  \/____/                  \/____/                  \/____/         
                                                                                                    
                                                                                                                                                                                                                                                                                      
)";
	std::cout << "Welcome to...\n";
	std::cout << "\x1b[" << CYAN_FG << "m";
	std::cout << GameOpening << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";

}

void UI::gameOver()
{
}

void UI::gameWin()
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

void UI::displayNotPrepared() 
{
	std::cout << "You were not prepared :(" << std::endl;
}

void UI::displayWelcome() {
	std::cout << "Welcome to our game!" << std::endl;
}

void UI::displayPickClass() 
{
	std::cout << "What kind of character do you want to be?" 	<< std::endl
	<< input_choice::new_spoon 		<< ") Spoon" 	<< std::endl
	<< input_choice::new_fork		<< ") Fork" 	<< std::endl
	<< input_choice::new_knife		<< ") Knife"	<< std::endl;
}

void UI::displayNamePrompt() 
{
	std::cout << "Enter a name for your character: ";
}

std::string UI::getCharacterName() 
{
	std::string name;
	std::cin >> name;
	return name;
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

int UI::getSaveInput() 
{
	int choice;
	std::cin >> choice;
	return choice;
}

void UI::displaySaveEntry(std::string character_name, int num) 
{
	std::cout << "Save entry " << num << ": " << character_name << std::endl;
}

void UI::displayCarryOn() 
{
	std::cout << "Do you want to continue playing?" << std::endl
	<< input_choice::carry_on 	<< ") Continue" 	<< std::endl 
	<< input_choice::quit 		<< ") Quit"			<< std::endl;
}
