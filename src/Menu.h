#include <list>
#include <map>
#include "Dish.h"

class Menu {
private:
    std::map<std::string, std::pair<Dish*, double>> menuItems;
public:
    void addDish(const std::string& key, Dish* dish, double cost);
    std::pair<Dish*, double> getDish(const std::string& key) ;
    void printMenu();
};
