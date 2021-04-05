#pragma once
#include <string>
#include <vector>

// The placeholders (need to define even in stubs eventually!)
typedef void* GAME_STATE; // Placeholder
typedef void* ITEM; // Placeholder


// Character ------------------------------------------------------------------

class Character {
	std::string name;
	
	int current_health;

	int max_health;
	
	int attack;

	int defense;

	int speed;

	enum character_class { spoon, fork, knife };

	Character* Character_PTR;
	
public:
	Character(std::string name, std::string character_class); // New character
	
	// Cpp has a built-in regex library; can use to represent
	//   Characters as a string (e.g., delimited string)
	Character(std::string restore); // Restore from saving

	void setHealth(int health);

	int getHealth();
	
	int getAttack();

	explicit operator std::string(); // To typecast a character to a string
};
// ----------------------------------------------------------------------------

// UI -------------------------------------------------------------------------
class UI {
	std::string User_character_Sprite;
	std::string Enemy_Sprite;

public:
	//void new_event(Character* character_ptr, Character* enemy_ptr, event_type); // event type should be from game logic but I'm not sure what the form of it is yet
	void new_turn();
	int get_input();
	void get_sprite(Character* character_ptr);
	void get_sprite(Character* character_ptr, Character* enemy_ptr);
	void display_menu();		// requires context to be passed to it
	void initial_menu();
	void user_options();
	void game_opening();
};



// ----------------------------------------------------------------------------


// Level ----------------------------------------------------------------------

class Level {
	Character* playerCharacter;	//references to both player and enemy characters
	Character* enemyCharacter;
	Level* nextLevel;	//implemented in the form of a linked list
	Level* previousLevel;
	int difficulty;
public:
	Level();
	~Level();

	int enterCombat();
};

//-----------------------------------------------------------------------------


// ReadWrite ------------------------------------------------------------------
// NOTE: A filesystem module is available, but only for c++17
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
	std::vector<LoadEntry&> saves;
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
// ----------------------------------------------------------------------------



// OLD!

// Object ---------------------------------------------------------------------
// Note: We are planning to remove Objects from the product!

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
// ----------------------------------------------------------------------------

// We are also thinking of dropping items