/**
 * @file AddToDish.h
 * @brief Contains the declaration of the AddToDish class.
 */

#ifndef ADDTODISH_H
#define ADDTODISH_H

#include <iostream>
#include "DishDecorator.h"


/**
 * @class AddToDish
 * @brief The AddToDish class represents a decorator that adds an ingredient to a dish.
 */
class AddToDish : public DishDecorator {

private:
	std::string ingredient;
	double costOfIngredient;

public:
    /**
     * @brief Default constructor for AddToDish.
     */
	AddToDish();

    /**
     * @brief Set the ingredient to be added.
     * @param ingredient The ingredient to be added to the dish.
     */
    void setIngredient(std::string ingredient);

    /**
     * @brief Set the cost of the added ingredient.
     * @param costOfIngredient The cost associated with the added ingredient.
     */
    void setCostOfIngredient(double costOfIngredient);

    /**
     * @brief Add an ingredient to the dish.
     * @param ingredient The ingredient to add to the dish.
     */
    void addIngredient(std::string ingredient);

    /**
     * @brief Calculate the total cost of the dish.
     * @return The total cost of the dish.
     */
    double totalCost();

    /**
     * @brief Get the list of ingredients in the dish.
     * @return A string containing the list of ingredients in the dish.
     */
    std::string getIngredientsList();
};

#endif
