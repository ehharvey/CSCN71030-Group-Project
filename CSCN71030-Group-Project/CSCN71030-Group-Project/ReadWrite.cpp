#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "ReadWrite.h"

namespace fs = std::filesystem;
using json = nlohmann::json;

Loader::Loader() 
{
    fs::path current_path = fs::current_path();
    this->root = current_path / DEFAULT_PATH;

    // If path does not exist, create one
    if (!fs::is_directory(this->root))
    {
        fs::create_directory(this->root);
    }

    // Iterate through each file in directory
    for (auto const & entry : fs::recursive_directory_iterator(this->root))
    {
        // If entry is a file (and not a character file [linux] or directory [multiplat])
        if (fs::is_regular_file(entry))
        {
            // Creating a file could fail, catch it!
            try
            {
                load_entries.push_back(SaveEntry(entry));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
    }
}

std::vector<SaveEntry&> Loader::get_entries() 
{
    return this->load_entries;
}

SaveEntry::SaveEntry(std::filesystem::path full_path) : full_path(full_path), name(full_path.filename()), current_state(full_path)
{ }

SaveEntry::SaveEntry(std::filesystem::path name, std::filesystem::path directory, GameState current_state) : full_path(full_path),
                                                                                                             name(name),
                                                                                                             current_state(current_state)
{ }

void SaveEntry::saveToFile() 
{
    std::ofstream file;
    file.open(this->full_path, std::ios::out);
    file << this->current_state.jsonify();
    file.close();
}
