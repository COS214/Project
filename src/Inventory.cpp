#include "Inventory.h"

Inventory* Inventory::instance = 0;

Inventory* Inventory::getInstance() {
	if (instance == 0) {
		cout<<"Creating Inventory instance"<<endl;
		instance = new Inventory();
	}
	return instance;
}

void Inventory::initializeInventory(map<string, int> inventory)
{
	this->inventory = inventory;
}

Inventory::Inventory() {
	//
}

bool Inventory::addToInventory(string item, int count) {
		if (inventory.find(item) != inventory.end()) {
			// Item already exists in the inventory, add to the count
			inventory[item] += count;
		} else {
			// Item doesn't exist, create a new entry
			inventory[item] = count;
		}
		return true;  // You can add error handling logic if needed
	}

bool Inventory::removeFromInventory(string item, int count) {
        if (inventory.find(item) != inventory.end()) {
            if (inventory[item] >= count) {
                // Sufficient count of the item exists, remove from the count
                inventory[item] -= count;
                if (inventory[item] == 0) {
                    // If count reaches zero, remove the item from the inventory
                    inventory.erase(item);
                }
                return true;
            } else {
                // Not enough items to remove
                return false;
            }
        } else {
            // Item doesn't exist in the inventory
            return false;
        }
    }
