#include <iostream>
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

SaveEntry::SaveEntry(std::filesystem::path full_path) 
{
    json j = json::parse(full_path);
    json character = j["Character"];
    

}
