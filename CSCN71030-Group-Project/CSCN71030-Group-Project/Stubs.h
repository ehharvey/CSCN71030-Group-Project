#pragma once
#include <string>
#include <vector>

// Character
class Character {
	std::string name;
	
	int health;
	
	int attack;
	
public:
	Character(std::string name); // New character
	Character(std::string restore); // Restore from saving

	void setHealth(int health);
	
	int getAttack();

	explicit operator std::string();
};

// ReadWrite
// NOTE: A filesystem module is available, but only for c++17

typedef void* GAME_STATE; // Placeholder

class LoadEntry {
	std::string name;
	std::string full_path;
public:
	LoadEntry(std::string name, std::string full_path);
	~LoadEntry();

	std::string getName();
	GAME_STATE loadEntry();
};


class Loader {
	std::string root;
	std::vector<LoadEntry&> load_entries;
public:
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



// Object 
// Note: We are planning to remove Objects from the product!


typedef void* ITEM; // Placeholder


class ItemSlot {
	ITEM item; // TODO: change to &item
	int slot;
public:
	ItemSlot(ITEM item, int slot); // TODO: Change Item*
	~ItemSlot();

	int getSlot();
	void* getItem();
};

class Inventory {
	int _next_slot;
	int size;
	std::vector<ItemSlot&> container;
public:
	Inventory();
	~Inventory();

	void insertItem(ITEM item);
	void removeItem(ItemSlot& item_slot);

	std::vector<void*> getContainer(); // Returns copy of container
};


