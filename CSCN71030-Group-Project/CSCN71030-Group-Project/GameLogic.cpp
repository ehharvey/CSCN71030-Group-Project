#include <iostream>

enum Area { drawer, sink, counter, oven };

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