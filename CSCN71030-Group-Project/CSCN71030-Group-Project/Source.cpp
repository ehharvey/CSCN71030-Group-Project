

#include "UI.h"
#include "Level.h"
#include "ReadWrite.h"
#include "RNG.h"
#include "Character.h"


int main() {
	int userinput = 0;
	UI* ui = new UI();
	ui->game_opening();
	ui->initial_menu();
	userinput = ui->get_input();

	if (userinput == 1) {		// New game

		//get name from user
		std::string char_name = "Name";

		// get class selection from user
		userinput = ui->get_input();
		// if statements for class
		if (userinput == 1) {
			Character* UserChar = new spoon(char_name);
		}
		else if (userinput == 2) {
			Character* UserChar = new fork(char_name);
		}
		else {
			Character* UserChar = new knife(char_name);
		}

	}
	else if (userinput == 2) {	// Load game

		//load game

	}
	else {						// Exit

		return 0;
	}
	// switch case and while loop for game



}