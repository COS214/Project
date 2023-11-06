/**
 * @file RemoveFromDish.h
 * @brief Contains the declaration of the RemoveFromDish class.
 */

#ifndef REMOVEFROMDISH_H
#define REMOVEFROMDISH_H

#include <iostream>
#include "DishDecorator.h"

/**
 * @class RemoveFromDish
 * @brief The RemoveFromDish class represents a decorator for removing ingredients from a dish.
 */
class RemoveFromDish : public DishDecorator {
private:
	std::string ingredient;
    double costOfIngredient;

public:
	/**
     * @brief Default constructor for the RemoveFromDish class.
     */
	RemoveFromDish();
     ~RemoveFromDish()=default;

	/**
     * @brief Set the ingredient to be removed.
     * @param ingredient A string representing the ingredient to be removed.
     */
	void setIngredient(std::string ingredient);

	/**
     * @brief Set the cost of the removed ingredient.
     * @param costOfIngredient A double representing the cost of the removed ingredient.
     */
    void setCostOfIngredient(double costOfIngredient);

	/**
     * @brief Remove the specified ingredient from the dish.
     * @param ingredient A string representing the ingredient to be removed.
     */
	void removeIngredient(std::string ingredient);

	/**
     * @brief Calculate the total cost of the dish after ingredient removal.
     * @return The total cost of the modified dish.
     */
	double totalCost();

	/**
     * @brief Get the list of ingredients to be removed.
     * @return A string representing the list of removed ingredients.
     */
    std::string getIngredientsList();
};


#endif
