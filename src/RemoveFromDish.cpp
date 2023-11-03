#include <iostream>
#include <list>
#include <algorithm>

#include "RemoveFromDish.h"

RemoveFromDish::RemoveFromDish(){

}
    
void RemoveFromDish::setIngredient(std::string ingredient){
	this->ingredient = ingredient;
}

void RemoveFromDish::setCostOfIngredient(double costOfIngredient){
	this->costOfIngredient=costOfIngredient;
}

void RemoveFromDish::removeIngredient(std::string ingredient) {
	auto it = this->ingredientsForDish.begin();
	while (it != this->ingredientsForDish.end()) {
		if (*it == ingredient) {
			it = this->ingredientsForDish.erase(it);
			setCost(getCost() - costOfIngredient);
			return;
		} else {
			++it; 
		}
	}
	std::cout << "Ingredient is not part of the dish!" << std::endl;
}

double RemoveFromDish::totalCost(){  
	return getCost();
}

std::string RemoveFromDish::getIngredientsList() {
	std::string list= "";
	for (std::string& item : ingredientsForDish) 
	{
		
		list += item + "\n";
		
	}
	return list;
}