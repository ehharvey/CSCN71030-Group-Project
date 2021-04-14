
#include "ReadWrite.h"
#include "Character.h"
#include "UI.h"
#include <iostream>
#include <optional>
#include <cassert>
#include <windows.h>

/*
int main(void)
{
    // Get user choice to:
    // 1. Create new game (incl create new character)
    // 2. Load Game
    // 3. enter cheat codes
    // 4. exit

    // If new game,
    //   get player to create new character
    //   ask player if they want to save after making character

    // If load game, direct player to load game
    //   This includes getting a list of currently saved games
    //   and getting a user choice about which game to save
    //   (The user should be able to exit at most steps too!)

    // If Exit, exit the game :)


    // Main game flow
    Area a = drawer;
    bool playerSucceeded; // Returned from encounter stating whether user has succeeded (or died)


    switch (a)
    {
    case drawer:
        // Drawer level
        // If user died, display game over
        // If user succeeded, ask if user wants to save
    case sink:
        // Sink level
        // If user died, display game over
        // If user succeeded, ask if user wants to save
    case counter:
        // Counter level
        // If user died, display game over
        // If user succeeded, ask if user wants to save
    case oven:
        // Oven level
        // If user died, display game over
        // If user succeeded, ask if user wants to save
    }

    // Handle end-of-game things

    return EXIT_SUCCESS;
}
*/

int main(int argc, char* argv[]) {
    
	UI* ui = new UI();
	ui->game_opening();
    Sleep(500);
    input_choice user_new_or_load;

    Character* UserChar = NULL;
    std::string char_name;

    Loader loader = Loader();
    std::string cheatCode;
    std::optional<GameState> game_state;

    // New game or load?
    bool user_picked_valid_start;
    do {
        ui->displayMenu();
        user_new_or_load = ui->get_input();

        switch (user_new_or_load) {
        case new_character:

            bool valid_type_choice;
            do {
                // Tell user to pick a class
                ui->displayPickClass();
                
                // get class selection from user
                input_choice user_character_type = ui->get_input();

                switch (user_character_type) {
                case input_choice::new_spoon:
                    ui->displayNamePrompt();
                    char_name = ui->getCharacterName();
                    UserChar = new spoon(char_name);
                    valid_type_choice = true;
                    break;

                case input_choice::new_fork:
                    ui->displayNamePrompt();
                    char_name = ui->getCharacterName();
                    UserChar = new fork(char_name);
                    valid_type_choice = true;
                    break;

                case input_choice::new_knife:
                    ui->displayNamePrompt();
                    char_name = ui->getCharacterName();
                    UserChar = new knife(char_name);
                    valid_type_choice = true;
                    break;

                default:
                    valid_type_choice = false;
                }

            } while (!valid_type_choice);

            user_picked_valid_start = true;

            // Define Empty game state
            game_state = GameState(UserChar->jsonify());

            break;
        case load_game:
            // Display slots
            {
                 SaveEntry* entries = loader.get_entries();
                 int user_save_choice;
                 bool valid_save_choice;
                 do
                 {
                     // Display saves
                     for (int i = 0; i <= SaveSlot::three; i++)
                     {
                         std::optional<GameState> entry = entries[i].loadEntry();
                         if (entry.has_value())
                         {
                             ui->displaySaveEntry((entry->getCharacter())["name"], i);
                         }
                         else
                         {
                             ui->displaySaveEntry("EMPTY", i);
                         }
                     }

                     user_save_choice = ui->getSaveInput();

                     if ((user_save_choice < 0 || user_save_choice > 2) ||
                         (!entries[user_save_choice].loadEntry().has_value()))
                     {
                         valid_save_choice = false;
                     }
                     else
                     {
                         valid_save_choice = true;
                     }
                 } while (!valid_save_choice);

                // Load character from slot
                game_state = entries[user_save_choice].loadEntry();
                UserChar = new Character((json) game_state->getCharacter());

                user_picked_valid_start = true;
                break;
            }
        case cheat_code:
            //do something to accept console arguement
            std::cout << argv[1] << std::endl;
            cheatCode = argv[1];
            if (std::string(CheatCode1) == cheatCode) {
                ui->gameWin();
                exit(EXIT_SUCCESS);
            }
            else if (std::string(CheatCode2) == cheatCode) {        // prints credits

                std::string Credits[3][2] =
                { {"Rukia","Al-Amiri"}, {"Emil","Harvey"}, {"Cole","Foster"} };

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 2; j++) {
                        std::cout << Credits[i][j] << " ";
                    }
                    std::cout << " ";
                }
                std::cout << std::endl << std::endl << std::endl;
                user_picked_valid_start = false;
            }
            else if (std::string(CheatCode3) == cheatCode) {
                ui->display_Game_Over();
                exit(EXIT_SUCCESS);
            }
            else {
                ui->invalidCheatCode();                    // invalid cheat code
                user_picked_valid_start = false;
            }
            break;

        case exit_game:
            ui->displayGoodBye();
            exit(EXIT_SUCCESS);

        default:
            user_picked_valid_start = false;
        }
    } while (!user_picked_valid_start);
    

    // Ensure that we have a game state
    assert(game_state.has_value());

    for (int current_area = (int)game_state->getCurrentArea();
        current_area <= (int)stageType::Counter;
        current_area++)
    {
        Level level(UserChar, (stageType) current_area);

        combatStatus result = level.enterCombat();

        switch (result) {
            case Win:
            {
                ui->displaySavePrompt();
                input_choice to_save = ui->get_input();

                switch (to_save) {
                case save:
                {
                    Loader loader = Loader(); // Redundant
                    // Display slots
                    SaveEntry* entries = loader.get_entries();

                    for (int i = 0; i < SaveSlot::three; i++)
                    {
                        std::optional<GameState> entry = entries[i].loadEntry();
                        if (entry.has_value())
                        {
                            ui->displaySaveEntry((entry->getCharacter())["name"], i);
                        }
                        else
                        {
                            ui->displaySaveEntry("EMPTY", i);
                        }
                    }
                    json char_json = UserChar->jsonify();
                    GameState current_state = GameState(char_json, (stageType)(current_area + 1));
                    int save_slot = ui->getSaveInput();
                    entries[save_slot].setState(current_state);
                    entries[save_slot].saveToFile();
                    break;
                }

                case no_save:
                {
                    // do nothing
                    break;
                }

                default:
                {
                    // todo
                }
                }



                
                input_choice to_continue;

                bool user_picked_valid_carry_on;
                do
                {
                    ui->displayCarryOn();
                    to_continue = ui->get_input();

                    switch (to_continue)
                    {
                    case carry_on:
                        user_picked_valid_carry_on = true;
                        break;

                    case quit:
                        user_picked_valid_carry_on = true;
                        ui->displayGoodBye();
                        delete UserChar;
                        delete ui;
                        exit(EXIT_SUCCESS);

                    default:
                        user_picked_valid_carry_on = false;
                    }
                } while (!user_picked_valid_carry_on);
            }
            // Handle if they want to continue
            break;


            case Die:
            ui->display_Game_Over(UserChar);
            exit(EXIT_SUCCESS);
        }

        // Create level
        //      Level level(UserChar);
        // Execute level
        //      level.initiate()
        // If user died
        //      exit game
        // If user did not die
        //      ask if save
        //          if yes: save
        //      continue onwards :) (maybe ask if they want to continue)
    }



    ui->gameWin();
    delete UserChar;
    delete ui;
    return EXIT_SUCCESS;
}