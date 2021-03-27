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
	GameState(std::string character_as_str, int current_area);

	json getCharacter();
	int getCurrentArea();
};


// Emil: Maybe a load entry should have the option to save e.g., it is a generic entry
class SaveEntry {
	std::string name;
	std::filesystem::path full_path;
	GameState current_state;

public:
	SaveEntry(std::filesystem::path full_path);
	SaveEntry(std::filesystem::path name, std::filesystem::path directory, GameState current_state);

	std::string getName();
	GameState loadEntry();
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


class Save {
	std::string root;
	std::string name;
	bool _name_is_unique;
	bool _was_successful;
public:
	Save(std::string root, std::string name);

	bool nameIsUnique();
	bool wasSuccessful();
};