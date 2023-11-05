#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <iostream>

using namespace std;

class Inventory {

private:
	static Inventory* instance;
	map<string, int> inventory;
	Inventory();
	~Inventory();
public:
	static Inventory* getInstance();

public:
	void initializeInventory(map<string, int> inventory);
	bool removeFromInventory(string item, int count);
	bool addToInventory(string item, int count);
	void printInventory();
};

#endif
