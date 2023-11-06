/**
 * @file DishDecorator.h
 * @brief Contains the declaration of the DishDecorator class.
 */

#ifndef DISHDECORATOR_H
#define DISHDECORATOR_H

#include <iostream>
#include "Dish.h"

/**
 * @class DishDecorator
 * @brief The DishDecorator class is a base class for decorating Dish objects.
 */
class DishDecorator : public Dish {
    protected:
        Dish* component;
    public:
        /**
         * @brief Constructor for the DishDecorator class.
         */
        DishDecorator();

        /**
         * @brief Add an ingredient to the decorated Dish.
         *
         * @param ingredient The ingredient to add.
         */
        virtual void addIngredient(std::string);

        /**
         * @brief Remove an ingredient from the decorated Dish.
         *
         * @param ingredient The ingredient to remove.
         */
        virtual void removeIngredient(std::string);

        /**
         * @brief Add a special instruction to the decorated Dish.
         *
         * @param instruction The special instruction to add.
         */
        virtual void addSpecialInstruction(std::string);

        /**
         * @brief Set the cost of a specific ingredient in the decorated Dish.
         *
         * @param cost The cost of the ingredient.
         */
        virtual void setCostOfIngredient(double);

        /**
         * @brief Set a specific ingredient in the decorated Dish.
         *
         * @param ingredient The ingredient to set.
         */
        virtual void setIngredient(std::string);

        /**
         * @brief Calculate the total cost of the decorated Dish.
         *
         * @return The total cost of the decorated Dish.
         */
        virtual double totalCost();

        /**
         * @brief Get a list of ingredients in the decorated Dish.
         *
         * @return A list of ingredients in the decorated Dish.
         */
        virtual std::string getIngredientsList();

        /**
         * @brief Set the component (Dish) to be decorated.
         *
         * @param newComponent The Dish component to decorate.
         */
        void setComponent(Dish* newComponent);

        /**
         * @brief Destructor for the DishDecorator class.
         */
        virtual ~DishDecorator();
};

#endif
