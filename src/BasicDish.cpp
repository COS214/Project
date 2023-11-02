#include <iostream>
#include "BasicDish.h"


BasicDish::BasicDish(std::string name) : Dish(name) {
	
};

double BasicDish::totalCost() {
	// cost of actual basic dish must be found where menu and associated prices of dishes are stores
	// use the id of the dish or name to search for it and then return the cost of that basic dish
	return cost;
}

