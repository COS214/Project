/**
 * @file Inventory.cpp
 * @brief Contains the declaration of the Inventory class functions.
 */

#include "Inventory.h"

Inventory* Inventory::instance = 0;

Inventory* Inventory::getInstance() {
	if (instance == 0) {
		cout<<"Inventory instance has been created!"<<endl;
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

Inventory::~Inventory()
{
	delete instance;
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
    
    void Inventory::printInventory()
    {
        for (const auto& pair : inventory) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }

bool Inventory::removeFromInventory(string item, int count) {
        if (inventory.find(item) != inventory.end()) {
            if (inventory[item] >= count) {
                // Sufficient count of the item exists, remove from the count
                inventory[item] -= count;
                if (inventory[item] == 0) {
                    // If count reaches zero, remove the item from the inventory
                    // inventory.erase(item);
                    cout<<"Item "<<item<<" is out of stock!"<<endl;
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
