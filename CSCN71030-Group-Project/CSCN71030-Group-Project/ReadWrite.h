#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#define DEFAULT_PATH "saves"


// NOTE: A filesystem module is available, but only for c++17

typedef void* GAME_STATE; // Placeholder

// Possible implementation of game state
class GameState {
	json character_json;
	int current_area;
public:
	GameState(std::filesystem::path full_path);
	GameState(json character_json, int current_area) : character_json(character_json), current_area(current_area) {};

	json getCharacter();
	int getCurrentArea();
	json jsonify();
};


// Emil: Maybe a load entry should have the option to save e.g., it is a generic entry
class SaveEntry {
	std::filesystem::path name;
	std::filesystem::path full_path;
	GameState current_state;

public:
	SaveEntry(std::filesystem::path full_path);
	SaveEntry(std::filesystem::path name, std::filesystem::path directory, GameState current_state);

	std::string getName();
	GameState loadEntry();

	void saveToFile();
};


class Loader {
	std::filesystem::path root;
	std::vector<SaveEntry&> load_entries;
public:
	Loader();
	Loader(std::string root);
	~Loader();

	std::vector<SaveEntry&> get_entries();
};