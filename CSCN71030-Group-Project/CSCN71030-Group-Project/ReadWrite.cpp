#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "ReadWrite.h"

namespace fs = std::filesystem;
using json = nlohmann::json;

const std::string SAVENAMES[] = { "One.json", "Two.json", "Three.json" };

Loader::Loader() 
{
    fs::path current_path = fs::current_path();
    this->root = current_path / DEFAULT_PATH;

    // If path does not exist, create one
    if (!fs::is_directory(this->root))
    {
        fs::create_directory(this->root);
    }

    // Find save slots 1 2 and 3
    for (SaveSlot slot = SaveSlot::one; slot <= SaveSlot::three; slot = (SaveSlot)((int)slot + 1))
    {
        this->saves[slot] = SaveEntry(this->root, slot);
    }
}

SaveEntry* Loader::get_entries() 
{
    return this->saves;
}

void SaveEntry::saveToFile() 
{
    if (current_state.has_value())
    {
        std::ofstream file;
        file.open(this->full_path, std::ios::out);
        file << this->current_state->jsonify();
        file.close();
    }
    else
    {
        // Handle Error
    }
}

json GameState::getCharacter() 
{
    return this->character_json;
}

stageType GameState::getCurrentArea() 
{
    return this->current_area;
}

json GameState::jsonify() 
{
    json result;
    result["Character"] = this->getCharacter();
    result["Current Area"] = this->current_area;
    
    return result;
}

SaveEntry::SaveEntry()
{
}

SaveEntry::SaveEntry(std::filesystem::path root, SaveSlot slot)
{
    full_path = root / SAVENAMES[slot];

    if (fs::is_regular_file(full_path))
    {
        this->current_state = GameState(this->full_path);
    }
    else
    {
        this->current_state = {};
    }
}

std::optional<GameState> SaveEntry::loadEntry() 
{
    return this->current_state;
}

void SaveEntry::setState(GameState game_state) 
{
    this->current_state = game_state;
}



GameState::GameState(json character_json)
{
    this->character_json = character_json;
    this->current_area = Drawer;
}

GameState::GameState(std::filesystem::path full_path)
{
    std::ifstream i(full_path);
    json j;
    i >> j;

    this->character_json = j["Character"];
    this->current_area = j["Current Area"];
}
