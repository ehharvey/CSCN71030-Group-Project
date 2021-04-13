#ifndef READWRITE_H
#define READWRITE_H


#pragma once
#include <string>
#include <vector>
#include <optional>
#include <filesystem>
#include <nlohmann/json.hpp>
#include "Level.h"

using json = nlohmann::json;

#define DEFAULT_PATH "saves"

enum SaveSlot { one = 0, two = 1, three = 2 };

// NOTE: A filesystem module is available, but only for c++17

// Possible implementation of game state
class GameState {
	json character_json;
	stageType current_area;
public:
	GameState(json character_json);
	GameState(std::filesystem::path full_path);
	GameState(json character_json, stageType current_area) : character_json(character_json), current_area(current_area) {};

	json getCharacter();
	stageType getCurrentArea();
	json jsonify();
};


// Emil: Maybe a load entry should have the option to save e.g., it is a generic entry
class SaveEntry {
	std::filesystem::path full_path;
	std::optional<GameState> current_state;

public:
	SaveEntry();
	SaveEntry(std::filesystem::path root, SaveSlot slot);

	GameState loadEntry();

	void saveToFile();
};


class Loader {
	std::filesystem::path root;
	SaveEntry saves[3];
public:
	Loader();
	Loader(std::string root);

	SaveEntry* get_entries();
};

#endif // !READWRITE_H