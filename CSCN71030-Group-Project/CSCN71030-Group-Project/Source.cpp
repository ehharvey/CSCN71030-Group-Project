
#include "ReadWrite.h"
#include "Character.h"
#include "UI.h"
#include <iostream>
#include <optional>
#include <cassert>

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
	ui->initial_menu();
    input_choice user_new_or_load = ui->get_input();

    Character* UserChar = NULL;
    std::string char_name;

    std::optional<GameState> game_state;

    // New game or load?
    bool user_picked_valid_start;
    do {
        switch (user_new_or_load) {
        case new_character:

            bool valid_type_choice;
            do {
                // Tell user to pick a class

                // get class selection from user
                input_choice user_character_type = ui->get_input();

                switch (user_character_type) {
                case input_choice::new_spoon:
                    UserChar = new spoon(char_name);
                    valid_type_choice = true;
                    break;
                case input_choice::new_fork:
                    UserChar = new fork(char_name);
                    valid_type_choice = true;
                    break;
                case input_choice::new_knife:
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

            // Retrieve a slot

            // Load character from slot

            // Also ensure game state is properly started here

            user_picked_valid_start = true;
            break;
        default:
            user_picked_valid_start = false;
        }
    } while (user_picked_valid_start);
    

    // Ensure that we have a game state
    assert(game_state.has_value());

    for (int current_area = (int)game_state->getCurrentArea();
        current_area <= (int)stageType::Counter;
        current_area++)
    {
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