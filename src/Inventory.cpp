/**
 * @file Inventory.cpp
 * @brief Contains the declaration of the Inventory class functions.
 */

#include "Inventory.h"

Inventory *Inventory::instance = 0;
/**
 * @brief This method returns the singleton instance of the Inventory class.
 *
 * @return Pointer to the singleton instance of the Inventory class.
 */
Inventory *Inventory::getInstance()
{
    if (instance == 0)
    {
        // cout<<"Inventory instance has been created!"<<endl;
        instance = new Inventory();
    }
    return instance;
}
/**
 * @brief This method initializes the inventory with a given map.
 *
 * @param inventory Map representing the inventory to be initialized.
 */
void Inventory::initializeInventory(map<string, int> inventory)
{
    this->inventory = inventory;
}
/**
 * @brief Default constructor for the Inventory class.
 */
Inventory::Inventory()
{
    //
}
/**
 * @brief Destructor for the Inventory class. Deletes the singleton instance.
 */
Inventory::~Inventory()
{
    delete instance;
}
/**
 * @brief This method allows an item to be added to the inventory.
 *
 * @param item String representing the name of the item to be added.
 * @param count Integer representing the count of the item to be added.
 * @return true if the item is successfully added, false otherwise.
 */
bool Inventory::addToInventory(string item, int count)
{
    if (inventory.find(item) != inventory.end())
    {
        // Item already exists in the inventory, add to the count
        inventory[item] += count;
    }
    else
    {
        // Item doesn't exist, create a new entry
        inventory[item] = count;
    }
    return true; // You can add error handling logic if needed
}
/**
 * @brief This method prints the inventory to the console.
 */
void Inventory::printInventory()
{
    std::cout << "\033[0;34m--------------------------------------------" << std::endl;
    std::cout << "\t\tINVENTORY: " << std::endl;
    for (const auto &pair : inventory)
    {

        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    std::cout << "--------------------------------------------\033[0m" << std::endl;
}
/**
 * @brief This method allows an item to be removed from the inventory.
 *
 * @param item String representing the name of the item to be removed.
 * @param count Integer representing the count of the item to be removed.
 * @return true if the item is successfully removed, false otherwise.
 */
bool Inventory::removeFromInventory(string item, int count)
{
    if (inventory.find(item) != inventory.end())
    {
        if (inventory[item] >= count)
        {
            // Sufficient count of the item exists, remove from the count
            inventory[item] -= count;
            if (inventory[item] == 0)
            {
                // If count reaches zero, remove the item from the inventory
                // inventory.erase(item);
                cout << "Item " << item << " is out of stock!" << endl;
            }
            return true;
        }
        else
        {
            // Not enough items to remove
            return false;
        }
    }
    else
    {
        // Item doesn't exist in the inventory
        return false;
    }
}
