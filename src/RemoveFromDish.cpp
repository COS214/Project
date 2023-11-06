/**
 * @file RemoveFromDish.cpp
 * @brief Contains the declaration of the RemoveFromDish class functions.
 */

#include <iostream>
#include <list>
#include <algorithm>

#include "RemoveFromDish.h"

RemoveFromDish::RemoveFromDish()
{
}
/**
 * @brief This method sets the ingredient to be removed from the dish.
 *
 * @param ingredient String representing the name of the ingredient to be set.
 */
void RemoveFromDish::setIngredient(std::string ingredient)
{
	this->ingredient = ingredient;
}
/**
 * @brief This method sets the cost of the ingredient to be removed from the dish.
 *
 * @param costOfIngredient Double representing the cost of the ingredient to be set.
 */
void RemoveFromDish::setCostOfIngredient(double costOfIngredient)
{
	this->costOfIngredient = costOfIngredient;
}
/**
 * @brief This method removes a specific ingredient from the dish.
 *
 * @param ingredient String representing the name of the ingredient to be removed.
 */
void RemoveFromDish::removeIngredient(std::string ingredient)
{
	auto it = this->ingredientsForDish.begin();
	while (it != this->ingredientsForDish.end())
	{
		if (*it == ingredient)
		{
			it = this->ingredientsForDish.erase(it);
			setCost(getCost() - costOfIngredient);
			return;
		}
		else
		{
			++it;
		}
	}
	std::cout << "Ingredient is not part of the dish!" << std::endl;
}
/**
 * @brief This method returns the total cost of the dish after removing the ingredient.
 *
 * @return Double representing the total cost of the dish.
 */
double RemoveFromDish::totalCost()
{
	return getCost();
}
/**
 * @brief This method returns a list of ingredients in the dish.
 *
 * @return String representing the list of ingredients in the dish.
 */
std::string RemoveFromDish::getIngredientsList()
{
	std::string list = "";
	for (std::string &item : ingredientsForDish)
	{

		list += item + "\n";
	}
	return list;
}