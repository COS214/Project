/**
 * @file AddToDish.cpp
 * @brief Contains the implementation of the AddToDish class.
 */

#include "AddToDish.h"
#include <iostream>
#include <list>
AddToDish::AddToDish()
{
}
/**
 * @brief  Sets the ingredient for the dish.
 * @param  ingredient The ingredient to be set.
 */
void AddToDish::setIngredient(std::string ingredient)
{
	this->ingredient = ingredient;
}
/**
 * @brief  Sets the cost of the ingredient.
 * @param  costOfIngredient The cost of the ingredient.
 */
void AddToDish::setCostOfIngredient(double costOfIngredient)
{
	this->costOfIngredient = costOfIngredient;
}
/**
 * @brief  Adds an ingredient to the dish.
 * @param  ingredient The ingredient to be added.
 */
void AddToDish::addIngredient(std::string ingredient)
{
	this->ingredientsForDish.push_back(ingredient);
	double newCost = this->getCost() + costOfIngredient;
	setCost(newCost);
}
/**
 * @brief  Gets the total cost of the dish.
 * @return The total cost of the dish.
 */
double AddToDish::totalCost()
{
	return getCost();
}
/**
 * @brief  Gets the list of ingredients for the dish.
 * @return The list of ingredients.
 */
std::string AddToDish::getIngredientsList()
{
	std::string list = "";
	for (std::string &item : ingredientsForDish)
	{
		list += item + "\n";
	}
	return list;
}