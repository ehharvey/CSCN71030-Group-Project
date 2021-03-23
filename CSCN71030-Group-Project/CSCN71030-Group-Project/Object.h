#pragma once
#include <vector>

class Inventory {
	int size;
	std::vector<void*> container; // TODO: Change to Item*
public:
	Inventory();
	~Inventory();

	void insertItem(void* item);
	std::vector<void*> getContainer(); // Returns copy of container
};