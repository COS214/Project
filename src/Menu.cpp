/**
 * @file Menu.cpp
 * @brief Contains the declaration of the Menu class functions.
 */

#include "Menu.h"

void Menu::addDish(const std::string& key, Dish* dish, double cost) {
        menuItems[key] = std::make_pair(dish, cost);
    }

std::pair<Dish*, double> Menu::getDish(const std::string& key) {
    auto it = menuItems.find(key);
    if (it != menuItems.end()) {
        return it->second;
    }
    return std::make_pair(nullptr, 0.0); // Dish not found
}

void Menu::printMenu() {
    std::cout << "Menu:\n";
    for (const auto& item : menuItems) {
        const std::string& key = item.first;
        Dish* dish = item.second.first;
        double cost = item.second.second;
        std::cout << key << " - " << dish->getName() << " - Cost: $" << cost << std::endl;
    }
}