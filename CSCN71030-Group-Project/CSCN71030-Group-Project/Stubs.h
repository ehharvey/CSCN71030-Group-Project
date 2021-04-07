#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
// The placeholders (need to define even in stubs eventually!)
typedef void* GAME_STATE; // Placeholder
typedef void* ITEM; // Placeholder


// Character ------------------------------------------------------------------

using json = nlohmann::json;

class Character {
	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	Character* Character_PTR;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;
	bool isPrepared;

public:

	Character();											// Default constructor

	Character(std::string name);							// New character

	Character(json j);

	virtual json jsonify();

	virtual void setHealth(int health_reduction);

	virtual int getHealth();

	virtual int getAttack();

	virtual int getDefence();

	virtual int getSpeed();

	virtual std::string getSprite();

	virtual std::string getFightSprite();

	virtual std::string getDeadSprite();

	virtual std::string getName();

	virtual bool getPrepared();

	virtual bool setPrepared(bool);

};


class spoon : public Character {

	std::string name;
	int current_health;
	int max_health = 10;
	int attack = 5;
	int defence = 10;
	int speed = 4;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	spoon();												// Default constructor
	spoon(std::string name);								// New spoon character
	json jsonify();
};

class fork : public Character {

	std::string name;
	int current_health;
	int max_health = 7;
	int attack = 7;
	int defence = 5;
	int speed = 10;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	fork();												// Default constructor
	fork(std::string name);								// New fork character
	json jsonify();
};


class knife : public Character {

	std::string name;
	int current_health;
	int max_health = 5;
	int attack = 10;
	int defence = 2;
	int speed = 8;
	std::string sprite;
	std::string fight_sprite;
	std::string dead_sprite;

	Character* Character_PTR;
	bool isPrepared;

public:
	knife();												// Default constructor
	knife(std::string name);								// New knife character
	json jsonify();
};

class DrawerEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	DrawerEnemy(int, int, int, int);												// Constructor
};

class DrawerBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	DrawerBoss(int, int, int, int);												// Constructor
};

class SinkEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	SinkEnemy(int, int, int, int);												// Constructor
};

class SinkBoss : public Character {
	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	SinkBoss(int, int, int, int);												// Constructor
};

class OvenEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	OvenEnemy(int, int, int, int);												// Constructor
};
class OvenBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	OvenBoss(int, int, int, int);												// Constructor
};
class CounterEnemy : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	CounterEnemy(int, int, int, int);												// Constructor
};
class CounterBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	CounterBoss(int, int, int, int);												// Constructor
};

class FinalBoss : public Character {

	std::string name;
	int current_health;
	int max_health;
	int attack;
	int defence;
	int speed;
	std::string sprite;
	std::string dead_sprite;

	Character* Enemy_PTR;
	bool isPrepared;

public:
	FinalBoss(int, int, int, int);												// Constructor
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