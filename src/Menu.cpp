/**
 * @file Menu.cpp
 * @brief Contains the declaration of the Menu class functions.
 */

#include "Menu.h"
/**
 * @brief This method allows a dish to be added to the menu.
 *
 * @param key String representing the key of the dish to be added.
 * @param dish Pointer to the Dish object to be added.
 * @param cost Double representing the cost of the dish to be added.
 */
void Menu::addDish(const std::string &key, Dish *dish, double cost)
{
    menuItems[key] = std::make_pair(dish, cost);
}
/**
 * @brief This method returns a dish from the menu based on a given key.
 *
 * @param key String representing the key of the dish to be returned.
 * @return Pair consisting of a pointer to the Dish object and its cost.
 */
std::pair<Dish *, double> Menu::getDish(const std::string &key)
{
    auto it = menuItems.find(key);
    if (it != menuItems.end())
    {
        return it->second;
    }
    return std::make_pair(nullptr, 0.0); // Dish not found
}
/**
 * @brief This method prints the menu to the console.
 */
void Menu::printMenu()
{
    std::cout << "\033[0;91m-----------------------------------------\033[0m" << std::endl; // Start with dark red
    std::cout << "\033[0;91m\t\tMENU:\n\033[0m";                                            // Reset after "Menu:"
    for (const auto &item : menuItems)
    {
        const std::string &key = item.first;
        Dish *dish = item.second.first;
        double cost = item.second.second;
        std::cout << "\033[91m " << key << " - " << dish->getName() << " - Cost: R" << cost << std::endl;
    }
    std::cout << "\033[0;91m-----------------------------------------\033[0m" << std::endl; // End with dark red
}
