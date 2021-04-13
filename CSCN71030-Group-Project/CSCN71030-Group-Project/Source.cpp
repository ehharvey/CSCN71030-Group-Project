
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
    // 3. Exit

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

int main() {
    
	UI* ui = new UI();
	ui->game_opening();
    Sleep(500);
	ui->initial_menu();
    input_choice user_new_or_load;

    Character* UserChar = NULL;
    std::string char_name;

    Loader loader = Loader();

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
                               
            
                // Retrieve a slot
                int user_choice = ui->getSaveInput();
                

                // Load character from slot
                game_state = entries[user_choice].loadEntry();
                UserChar = new Character((json) game_state->getCharacter());

                user_picked_valid_start = true;
                break;
            }
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
            }
            // Handle if they want to continue
            break;


            case Die:
            ui->displayGameOver(UserChar);
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

	
    return EXIT_SUCCESS;
}