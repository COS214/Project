#include "concreteMediator.h"

void concreteMediator::notify(Chefs* sender, std::string event){
	if (event == "cook") {
            if (sender == headChef_) {
                std::cout << "Head chef notifies: Dish is ready." << std::endl;
            } 
			else if (sender == juniorChef_) {
                std::cout << "Junior chef notifies: Dish is ready." << std::endl;
            }
			else if (sender == meatChef_) {
                std::cout << "Meat chef notifies: Dish is ready." << std::endl;
            }
			else if (sender == sauceChef_) {
                std::cout << "Sauce chef notifies: Dish is ready." << std::endl;
            }
			else if (sender == vegChef_) {
                std::cout << "Vegetable chef notifies: Dish is ready." << std::endl;
            }
        }
}
