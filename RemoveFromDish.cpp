#include <iostream>
#include <list>
#include <algorithm>

#include "RemoveFromDish.h"

RemoveFromDish::RemoveFromDish(std::string name):DishDecorator(name) {

}

void RemoveFromDish::setIngredient(std::string ingredient){
	this->ingredient = ingredient;
}

void RemoveFromDish::setCostOfIngredient(double costOfIngredient){
	this->costOfIngredient=costOfIngredient;
}

void RemoveFromDish::removeIngredient(std::string ingredient){
	auto it = find(ingredientsForDish.begin(), ingredientsForDish.end(), ingredient);
	if (it != ingredientsForDish.end()) {
		ingredientsForDish.erase(it);
		setCost(getCost()-costOfIngredient);
		return;
	}
	std::cout << "Ingredient is not part of the dish!" << std::endl;
};

double RemoveFromDish::totalCost(){  
	return getCost();
};
