/**
 * @file concreteMediator.cpp
 * @brief Contains the implementation of the concreteMediator class.
 */

#include "concreteMediator.h"

void concreteMediator::notify(Chefs* sender, std::string event){
	if (event == "cook") {
            if (sender == headChef_) {
                std::cout << "Head chef notifies: The dish is ready to be passed on. \n" << std::endl;
            } 
			else if (sender == juniorChef_) {
                std::cout << "Junior chef notifies: The dish is ready to be passed on. \n" << std::endl;
            }
			else if (sender == meatChef_) {
                std::cout << "Meat chef notifies: The dish is ready to be passed on. \n" << std::endl;
            }
			else if (sender == sauceChef_) {
                std::cout << "Sauce chef notifies: The dish is ready to be passed on. \n" << std::endl;
            }
			else if (sender == vegChef_) {
                std::cout << "Vegetable chef notifies: The dish is ready to be passed on. \n" << std::endl;
            }
        }
}

 concreteMediator::~concreteMediator(){
    delete headChef_;
    delete juniorChef_;
    delete meatChef_;
    delete sauceChef_;
    delete vegChef_;
 };