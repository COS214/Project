/**
 * @file Menu.h
 * @brief Contains the declaration of the Menu class.
 */

#include <list>
#include <map>
#include "Dish.h"

/**
 * @class Menu
 * @brief The Menu class represents a menu that contains various dishes.
 */
class Menu {
private:
    std::map<std::string, std::pair<Dish*, double>> menuItems;
public:
    /**
     * @brief Add a dish to the menu with its name and cost.
     * @param key A string representing the name of the dish.
     * @param dish A pointer to the Dish object to be added to the menu.
     * @param cost A double representing the cost of the dish.
     */
    void addDish(const std::string& key, Dish* dish, double cost);

    /**
     * @brief Get a dish from the menu by its name.
     * @param key A string representing the name of the dish to retrieve.
     * @return A pair containing a pointer to the Dish and its cost, or nullptr if not found.
     */
    std::pair<Dish*, double> getDish(const std::string& key) ;

    /**
     * @brief Print the contents of the menu.
     */
    void printMenu();
};
