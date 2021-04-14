#include "UI.h"
#include <iostream>
#include <string>
#include <windows.h>


input_choice UI::get_input()
{
	std::string user_input;
	std::cin >> user_input;

	unsigned char choice;
	try {
		choice = (unsigned char)std::stoi(user_input);
	}
	catch (const std::invalid_argument)
	{
		choice = -1;
	}
	

	return (input_choice)choice; // Seems brittle
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

void UI::display_Game_Over()
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
	std::cout << std::endl;
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
	std::cout << "\x1b[" << YELLOW_FG << "m";
	std::string Fight = R"(
   _______________ ________
  / __/  _/ ___/ // /_  __/
 / _/_/ // (_ / _  / / /   
/_/ /___/\___/_//_/ /_/                                                                                                                                                                                                                                                                             
)";
	std::cout << Fight << std::endl;
	std::cout << enemy_ptr->getSprite() << std::endl;
	std::cout << character_ptr->getFightSprite() << std::endl;
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
	std::cout << "Welcome to...\n\n\n\n\n\n\n\n\n";
	Sleep(1000);
	std::cout << "...building up suspense...\n";
	Sleep(1000);
	std::cout << "\x1b[" << CYAN_FG << "m";
	std::cout << GameOpening << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";

}



void UI::displayMenu()
{
	std::string GamePrompt = R"(
  _   _       _   _ _   _          _    ____                      
 | | | |_ __ | |_(_) |_| | ___  __| |  / ___| __ _ _ __ ___   ___ 
 | | | | '_ \| __| | __| |/ _ \/ _` | | |  _ / _` | '_ ` _ \ / _ \
 | |_| | | | | |_| | |_| |  __/ (_| | | |_| | (_| | | | | | |  __/
  \___/|_| |_|\__|_|\__|_|\___|\__,_|  \____|\__,_|_| |_| |_|\___|                                                                                                                                                                                                                                                                                                                  
)";

	std::string NewGame = R"(
  _  _               ___                
 | \| |_____ __ __  / __|__ _ _ __  ___ 
 | `/ / -_) V  V / | '_ / _` | '  \/ -_)
 |_|\_\___|\_/\_/   \___\__,_|_|_|_\___|                                 
)";

	std::string LoadGame = R"(
  _                 _    ___                
 | |   ___  __ _ __| |  / __|__ _ _ __  ___ 
 | |__/ _ \/ _` / _` | | `_ / _` | '  \/ -_)
 |____\___/\__,_\__,_|  \___\__,_|_|_|_\___|                                                
)";

	std::string CheatCode = R"(
    _      _   _          _          ___ _             _      ___         _     
   /_\  __| |_(_)_ ____ _| |_ ___   / __| |_  ___ __ _| |_   / __|___  __| |___ 
  / _ \/ _|  _| \ V / _` |  _/ -_) | (__| ' \/ -_) _` |  _| | (__/ _ \/ _` / -_)
 /_/ \_\__|\__|_|\_/\__,_|\__\___|  \___|_||_\___\__,_|\__|  \___\___/\__,_\___|                                                                                                                                                                          
)";
	std::string ExitGame = R"(
  ___     _ _   
 | __|_ _(_) |_ 
 | _|\ \ / |  _|
 |___/_\_\_|\__|                                                                                      
)";

	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << GamePrompt << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout << "Select an option:" << std::endl;
	std::cout << input_choice::new_character << ")" << NewGame << std::endl;
	std::cout << input_choice::load_game << ")" << LoadGame << std::endl;
	std::cout << input_choice::cheat_code << ")" << CheatCode << std::endl;
	std::cout << input_choice::exit_game << ")" << ExitGame << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::gameWin() {
	std::string WIN = R"(



                                                                                                                   
 _____      _____        _____     ____   ____         _____                   _____  _____   ______          ____ 
|\    \    /    /|  ____|\    \   |    | |    |       |\    \   _____     ____|\    \|\    \ |\     \        |    |
| \    \  /    / | /     /\    \  |    | |    |       | |    | /    /|   /     /\    \\\    \| \     \       |    |
|  \____\/    /  //     /  \    \ |    | |    |       \/     / |    ||  /     /  \    \\|    \  \     |      |    |
 \ |    /    /  /|     |    |    ||    | |    |       /     /_  \   \/ |     |    |    ||     \  |    |      |    |
  \|___/    /  / |     |    |    ||    | |    |      |     // \  \   \ |     |    |    ||      \ |    |      |    |
      /    /  /  |\     \  /    /||    | |    |      |    |/   \ |    ||\     \  /    /||    |\ \|    |      |____|
     /____/  /   | \_____\/____/ ||\___\_|____|      |\ ___/\   \|   /|| \_____\/____/ ||____||\_____/|       ____
    |     | /     \ |    ||    | /| |    |    |      | |   | \______/ | \ |    ||    | /|    |/ \|   ||      |    |
    |_____|/       \|____||____|/  \|____|____|       \|___|/\ |    | |  \|____||____|/ |____|   |___|/      |____|
                                                              \|____|/    

    
                                                                                                                                                
                                                                                                                                                                                                                                                       
)";
	std::string WIN_POST = "You've vanquished your foes, becoming the most power piece of cutlery around.";

	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << WIN << std::endl;
	std::cout << "\x1b[" << BRIGHT_GREEN_FG << "m";
	std::cout << WIN_POST << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::enemyDodge() {
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << "\nEnemy dodged" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::enemyNotPrepared()
{
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << "\nEnemy wasn't prepared" << std::endl; // TODO
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::enemyAttackHit() {
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << "\nEnemy hit and dealt some damage" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::notPrepared()							// Notify user that they were not prepared :( )
{
	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << "\nNooo, you weren't ready" << std::endl; 
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	
}

void UI::userDodged()
{
	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << "\nYou dodged an attack! Nice one." << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::dodgeFail() {		// User didn't dodge
	std::cout << "\x1b[" << GREY_FG << "m";
	std::cout << "\nYou couldn't dodge, try losing a couple prongs" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::attackHit()
{
	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << "\nYou hit them! That's gotta hurt..." << std::endl;
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

void UI::displayBattleIntro(Character* main_character, Character* enemy)
{

	std::cout << "\x1b[" << YELLOW_FG << "m";
	std::string Fight = R"(
   _______________ ________
  / __/  _/ ___/ // /_  __/
 / _/_/ // (_ / _  / / /   
/_/ /___/\___/_//_/ /_/                                                                                                                                                                                                                                                                             
)";
	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << Fight << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout << main_character->getFightSprite() << std::endl;

	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << enemy->getSprite() << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout << enemy->getFightSprite() << std::endl;
}



void UI::displayBattleTurn(Character* main_character, Character* enemy) 
{
	
	std::cout << "You have: ";
	std::cout << "\x1b[" << BRIGHT_BLUE_FG << "m";
	std::cout << main_character->getHealth() << "/" << main_character->getMaxHealth();
	std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout <<  " HP" << std::endl;
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << "Enemy has: ";
	std::cout << enemy->getHealth();
	//std::cout << "\x1b[" << DEFAULT_FG << "m";
	std::cout << "/" << enemy->getMaxHealth() << " HP" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::displayNotPrepared() {
	std::cout << "\x1b[" << BRIGHT_RED_FG << "m";
	std::cout << "You were not prepared :(" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}


void UI::displayGoodBye()
{

	std::string Bye = R"(
  ___            ___          
 | _ )_  _ ___  | _ )_  _ ___ 
 | _ \ || / -_) | _ \ || / -_)
 |___/\_, \___| |___/\_, \___|
      |__/           |__/     
                                                                                                                                                                                                                                                                           
)";
	std::cout << "\x1b[" << BRIGHT_MAGENTA_FG << "m";
	std::cout << Bye << std::endl;
	std::cout << "See you soon!" << std::endl;
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



void UI::invalidCheatCode()
{
	std::cout << "Error: Invalid cheat code" << std::endl;
}

void UI::displayInvalidInput() {
	std::cout << "\x1b[" << GREY_FG << "m";
	std::cout << "\nInvalid input" << std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
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
	std::string ContinuePrompt = R"(
   ____            _   _                 ___  
  / ___|___  _ __ | |_(_)_ __  _   _  __|__ \ 
 | |   / _ \| '_ \| __| | '_ \| | | |/ _ \/ / 
 | |__| (_) | | | | |_| | | | | |_| |  __/_|  
  \____\___/|_| |_|\__|_|_| |_|\__,_|\___(_)  
                                                                                                                                                                                                                                                                                               
)";

	std::string Exit = R"(
  ___     _ _   
 | __|_ _(_) |_ 
 | _|\ \ / |  _|
 |___/_\_\_|\__|
                                      
)";

	std::string Continue = R"(
   ___         _   _              
  / __|___ _ _| |_(_)_ _ _  _ ___ 
 | (__/ _ \ ' \  _| | ' \ || / -_)
  \___\___/_||_\__|_|_||_\_,_\___|
                                         
)";
	std::cout << ContinuePrompt << std::endl;
	std::cout << "Do you want to continue playing?" << std::endl;
	std::cout << input_choice::carry_on << ")" <<  Continue << std::endl;
	std::cout << "\x1b[" << GREY_FG << "m";
	std::cout << input_choice::quit << ")" << Exit<< std::endl;
	std::cout << "\x1b[" << DEFAULT_FG << "m";
}

void UI::displayBattleChoices()
{
	//std::cout << "\x1b[" << BLUE_FG << "m";
	std::cout << "What do you want to do?" << std::endl;

		std::cout << "\x1b[" << GREY_FG << "m";
		std::cout << input_choice::attack << ") Attack" << std::endl;
		std::cout << input_choice::prepare << ") Prepare" << std::endl;
		std::cout << input_choice::dodge << ") Dodge" << std::endl;
		std::cout << "\x1b[" << DEFAULT_FG << "m";
}
