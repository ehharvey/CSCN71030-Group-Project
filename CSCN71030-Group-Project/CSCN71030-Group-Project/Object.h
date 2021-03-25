#pragma once
#include <vector>

class ItemSlot {
	void* item; // TODO: change to &item
	int slot;
public:
	ItemSlot(void* item, int slot); // TODO: Change Item*
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

	void insertItem(void* item);
	void removeItem(ItemSlot& item_slot);

	std::vector<void*> getContainer(); // Returns copy of container
};