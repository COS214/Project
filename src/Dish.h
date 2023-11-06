/**
 * @file Dish.h
 * @brief Contains the declaration of the Dish class.
 */

#ifndef DISH_H
#define DISH_H

#include <iostream>
#include <list>

/**
 * @class Dish
 * @brief The Dish class represents a dish with a name, cost, and ingredients.
 */
class Dish {

protected:
	std::string name;
	int id;
	double cost;
	std::list<std::string> ingredientsForDish;

public:
    /**
	 * @brief Constructor for the Dish class.
	 */
	Dish();

    /**
	 * @brief Add an ingredient to the dish.
	 * @param ingredient The ingredient to add.
	 */
    virtual void addIngredient(std::string);

    /**
	 * @brief Remove an ingredient from the dish.
	 * @param ingredient The ingredient to remove.
	 */
    virtual void removeIngredient(std::string);

    /**
	 * @brief Add a special instruction to the dish.
	 * @param instruction The special instruction to add.
	 */
    virtual void addSpecialInstruction(std::string);

    /**
	 * @brief Set the cost of a specific ingredient in the dish.
	 * @param cost The cost of the ingredient.
	 */
    virtual void setCostOfIngredient(double);

    /**
	 * @brief Set a specific ingredient in the dish.
	 * @param ingredient The ingredient to set.
	 */
    virtual void setIngredient(std::string);

    /**
	 * @brief Get a list of ingredients in the dish.
	 * @return A list of ingredients in the dish.
	 */
    virtual std::string getIngredientsList();

    /**
	 * @brief Calculate the total cost of the dish.
	 * @return The total cost of the dish.
	 */
	virtual double totalCost()=0;

    /**
	 * @brief Get the cost of the dish.
	 * @return The cost of the dish.
	 */
	virtual double getCost();

    /**
	 * @brief Get the name of the dish.
	 * @return The name of the dish.
	 */
    std::string getName();

    /**
	 * @brief Set the cost of the dish.
	 * @param cost The cost to set.
	 */
	virtual void setCost(double cost);

    /**
	 * @brief Set the name of the dish.
	 * @param name The name to set.
	 */
    void setName(std::string name);

    /**
	 * @brief Set the list of ingredients for the dish.
	 * @param ingredients The list of ingredients to set.
	 */
    void setIngredientsList(const std::list<std::string>& ingredients);

    /**
	 * @brief Get the list of ingredients in the dish.
	 * @return A list of ingredients in the dish.
	 */
    std::list<std::string> getList();

    /**
	 * @brief Destructor for the Dish class.
	 */
	virtual ~Dish();
};


#endif


