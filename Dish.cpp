#include <list>
#include <iostream>

#include "Dish.h"

using namespace std;

Dish::Dish(std::string name){
	this->name=name;
	// default values
	// we need to parse name of meal, and then search for values from a structure holding each item in the menu
	id = 113;
	cost = 10.0;
	ingredientsForDish.push_back("Bun");
	ingredientsForDish.push_back("Patty");
	ingredientsForDish.push_back("Lettuce");
	ingredientsForDish.push_back("Cheese");
	ingredientsForDish.push_back("Tomato Sauce");
}

string Dish::getIngredientsList() {
    string list = "-----------------------------------------------\n";
	for (const string& item : ingredientsForDish) 
	{
		list += item + "\n"; 
	}
	list+="-----------------------------------------------";
    
    return list;
}

double Dish::getCost(){
	// cost of actual basic dish must be found where menu and associated prices of dishes are stored
	// use the id of the dish or name to search for it and then return the cost of that basic dish
	return cost;
}

void Dish::setCost(double cost){
	this->cost = cost;
}


Dish::~Dish(){

};

