/**
 * @file AddToDish.cpp
 * @brief Contains the implementation of the AddToDish class.
 */

#include "AddToDish.h"
#include <iostream>
#include <list>
AddToDish::AddToDish() {

}

void AddToDish::setIngredient(std::string ingredient) {
	this->ingredient = ingredient;
}

void AddToDish::setCostOfIngredient(double costOfIngredient) {
	this->costOfIngredient = costOfIngredient;
}

void AddToDish::addIngredient(std::string ingredient) {
	this->ingredientsForDish.push_back(ingredient);
	double newCost = this->getCost() + costOfIngredient;
	setCost(newCost);
}


double AddToDish::totalCost(){
return getCost(); 
}

std::string AddToDish::getIngredientsList(){
	std::string list= "";
	for (std::string& item : ingredientsForDish) 
	{
		list += item + "\n";
	}
	return list;
}