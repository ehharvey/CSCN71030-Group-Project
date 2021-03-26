#pragma once
#include <string>
#include <vector>
#include <filesystem>

#define DEFAULT_PATH "saves"


// NOTE: A filesystem module is available, but only for c++17

typedef void* GAME_STATE; // Placeholder

// Possible implementation of game state
class GameState {
	std::string character_as_str;
	int current_area;
public:
	GameState(std::string character_as_str, int current_area);

	std::string get_character();
	int get_current_area();
};


// Emil: Maybe a load entry should have the option to save e.g., it is a generic entry
class LoadEntry {
	std::string name;
	std::filesystem::path full_path;
public:
	LoadEntry(std::filesystem::path full_path);
	~LoadEntry();

	std::string getName();
	GAME_STATE loadEntry();
};


class Loader {
	std::filesystem::path root;
	std::vector<LoadEntry&> load_entries;
public:
	Loader();
	Loader(std::string root);
	~Loader();

	std::vector<LoadEntry&> get_entries();
};

class Save {
	std::string root;
	std::string name;
	bool _name_is_unique;
	bool _was_successful;
public:
	Save(std::string root, std::string name);

	bool name_is_unique();
	bool was_successful();
};