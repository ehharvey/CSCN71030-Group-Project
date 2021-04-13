#include "UI.h"
#include <iostream>
#include <string>
#include <windows.h>

void UI::new_turn() {

}

input_choice UI::get_input() {
	unsigned char user_input;
	std::cin >> user_input;
	return (input_choice)user_input; // Seems brittle
}

void UI::display_Game_Over(Character* character_ptr)
{
	std::string GameOver = R"(
._____  .______  ._____.___ ._______     ._______  .___     ._______.______  
:_ ___\ :      \ :         |: .____/     : .___  \ |   |___ : .____/: __   \ 
|   |___|   .   ||   \  /  || : _/\      | :   |  ||   |   || : _/\ |  \____|
|   /  ||   :   ||   |\/   ||   /  \     |     :  ||   :   ||   /  \|   :  \ 
|. __  ||___|   ||___| |   ||_.: __/      \_. ___/  \      ||_.: __/|   |___\
 :/ |. |    |___|      |___|   :/           :/       \____/    :/   |___|    
 :   :/                                     :                                
     :                                                                       
                                                   
__  __           _               ______            __            __
\ \/ /___  __  _( )________     / ____/___  ____  / /_____  ____/ /
 \  / __ \/ / / /// ___/ _ \   / /   / __ \/ __ \/ //_/ _ \/ __  / 
 / / /_/ / /_/ / / /  /  __/  / /___/ /_/ / /_/ / ,< /  __/ /_/ /  
/_/\____/\__,_/ /_/   \___/   \____/\____/\____/_/|_|\___/\__,_/   
                                                                                                                                                                                                                                                                                
)";
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << GameOver << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout << character_ptr->getDeadSprite() << std::endl;
}

void UI::display_enemy_defeated(Character* enemy_ptr) {
	// Maybe call random and make if statements for different types of defeated messages like "Scrambled" or something
	std::string Defeated = R"(
  _____        __           _           _ 
 |  __ \      / _|         | |         | |
 | |  | | ___| |_ ___  __ _| |_ ___  __| |
 | |  | |/ _ \  _/ _ \/ _` | __/ _ \/ _` |
 | |__| |  __/ ||  __/ (_| | ||  __/ (_| |
 |_____/ \___|_| \___|\__,_|\__\___|\__,_|
                                          
                                                                                                                                                                                                                                                       
)";
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << Defeated << std::endl;
	std::cout << "\x1b[" << GREY_FG << "m";
	std::cout << enemy_ptr->getDeadSprite() << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
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
	Sleep(500);
	std::cout << GameOpening << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";

}

void UI::gameWin() {
	std::string WIN = R"(
____    ____  ______    __    __     ____    __    ____  ______   .__   __.     __  
\   \  /   / /  __  \  |  |  |  |    \   \  /  \  /   / /  __  \  |  \ |  |    |  | 
 \   \/   / |  |  |  | |  |  |  |     \   \/    \/   / |  |  |  | |   \|  |    |  | 
  \_    _/  |  |  |  | |  |  |  |      \            /  |  |  |  | |  . `  |    |  | 
    |  |    |  `--'  | |  `--'  |       \    /\    /   |  `--'  | |  |\   |    |__| 
    |__|     \______/   \______/         \__/  \__/     \______/  |__| \__|    (__) 
                                                                                    
                                          
                                                                                                                                                                                                                                                       
)";

	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << WIN << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}


void UI::displayPickClass() {
	std::string spoon = R"(
  ___                     
 / __|_ __  ___  ___ _ _  
 \__ \ '_ \/ _ \/ _ \ ' \ 
 |___/ .__/\___/\___/_||_|
     |_|                  
)";

	std::string fork = R"(
  ___        _   
 | __|__ _ _| |__
 | _/ _ \ '_| / /
 |_|\___/_| |_\_\          
)";
	std::string knife = R"(
  _  __     _  __     
 | |/ /_ _ (_)/ _|___ 
 | ' <| ' \| |  _/ -_)
 |_|\_\_||_|_|_| \___|
                                        
)";

	std::string CharacterSelection = R"(
   ____ _                          _              ____       _           _   _             
  / ___| |__   __ _ _ __ __ _  ___| |_ ___ _ __  / ___|  ___| | ___  ___| |_(_) ___  _ __  
 | |   | '_ \ / _` | '__/ _` |/ __| __/ _ \ '__| \___ \ / _ \ |/ _ \/ __| __| |/ _ \| '_ \ 
 | |___| | | | (_| | | | (_| | (__| ||  __/ |     ___) |  __/ |  __/ (__| |_| | (_) | | | |
  \____|_| |_|\__,_|_|  \__,_|\___|\__\___|_|    |____/ \___|_|\___|\___|\__|_|\___/|_| |_|                                                                                        
)";
	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << CharacterSelection << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout << "Pick a character:" << std::endl;

	std::cout << input_choice::new_spoon << ")" << spoon << std::endl << std::endl;
	std::cout << input_choice::new_fork << ")" << fork << std::endl << std::endl;
	std::cout << input_choice::new_knife << ")" << knife << std::endl << std::endl;
}


// Emil:
void UI::displayBattleIntro(Character* main_character, Character* enemy)
{
	std::cout << main_character->getFightSprite() << std::endl;

	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << enemy->getSprite() << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::displayBattleTurn(Character* main_character, Character* enemy) 
{
	std::cout << " You have: " << main_character->getHealth() << "/" << main_character->getMaxHealth() << " HP" << std::endl;
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << "Enemy has: " << enemy->getHealth() << "/" << enemy->getMaxHealth() << " HP" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::displayNotPrepared() {
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << "You were not prepared :(" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::displayWelcome() {						// Not needed since opening handles this
	std::cout << "Welcome to our game!" << std::endl;
}


void UI::displayNamePrompt() 
{
	std::cout << "\x1b[" << BRIGHT_CYAN_FG << "m";
	std::cout << "What shall we call you, oh brave utensil: ";
	std::cout << "\x1b[" << DEFAULT_FG << "m";
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

void UI::displayEnemyDeath(Character* enemy) // already have the display_enemy_defeated() function above, not needed
{
	std::cout << enemy->getDeadSprite() << std::endl
	<< "You defeated!" << std::endl;
}

void UI::displaySavePrompt() 
{
	std::string SavePrompt = R"(
  ____                 ___ 
 / ___|  __ ___   ____|__ \
 \___ \ / _` \ \ / / _ \/ /
  ___) | (_| |\ V /  __/_| 
 |____/ \__,_| \_/ \___(_) 
                                                                                                                                                                                                                                                     
)";

	std::string saveSelect = R"(
  ___               
 / __| __ ___ _____ 
 \__ \/ _` \ V / -_)
 |___/\__,_|\_/\___|
                                      
)";

	std::string dontSaveSelect = R"(
   ___         _   _                       _ _   _             _                  _           
  / __|___ _ _| |_(_)_ _ _  _ ___  __ __ _(_) |_| |_  ___ _  _| |_   ___ __ ___ _(_)_ _  __ _ 
 | (__/ _ \ ' \  _| | ' \ || / -_) \ V  V / |  _| ' \/ _ \ || |  _| (_-</ _` \ V / | ' \/ _` |
  \___\___/_||_\__|_|_||_\_,_\___|  \_/\_/|_|\__|_||_\___/\_,_|\__| /__/\__,_|\_/|_|_||_\__, |
                                                                                        |___/          
)";
	std::cout << "\x1b[" << CYAN_FG << "m";
	std::cout << SavePrompt << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout << "Would you like to save your game?" << std::endl;
	std::cout << input_choice::save << ")" << saveSelect << std::endl;
	std::cout << "\x1b[" << GREY_FG << "m";
	std::cout << input_choice::no_save << ")" << dontSaveSelect << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";

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
