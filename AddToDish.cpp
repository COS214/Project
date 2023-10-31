#include "AddToDish.h"
#include <iostream>
#include <list>

AddToDish::AddToDish(std::string name) : DishDecorator(name){
}
    
void AddToDish::setIngredient(std::string ingredient){
	this->ingredient = ingredient;
}

void AddToDish::setCostOfIngredient(double costOfIngredient){
	this->costOfIngredient=costOfIngredient;
}

void AddToDish::addIngredient(std::string ingredient){
	ingredientsForDish.push_back(ingredient);
	setCost(getCost()+costOfIngredient);
}

double AddToDish::totalCost(){  
	return getCost();
}