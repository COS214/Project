/**
 * @file DishDecorator.cpp
 * @brief Contains the declaration of the DishDecorator class functions.
 */

#include <iostream>
#include "DishDecorator.h"
/**
 * @brief Default constructor for the DishDecorator class.
 */
DishDecorator::DishDecorator()
{
}
/**
 * @brief This method allows an ingredient to be added to the dish.
 *
 * @param ingredient String representing the name of the ingredient to be added.
 */
void DishDecorator::addIngredient(std::string)
{
}
/**
 * @brief This method allows an ingredient to be removed from the dish.
 *
 * @param ingredient String representing the name of the ingredient to be removed.
 */
void DishDecorator::removeIngredient(std::string)
{
}
/**
 * @brief This method allows a special instruction to be added to the dish.
 *
 * @param instruction String representing the special instruction to be added.
 */
void DishDecorator::addSpecialInstruction(std::string)
{
}
/**
 * @brief This method sets the cost of the ingredient for the dish.
 *
 * @param cost Double representing the cost of the ingredient to be set.
 */
void DishDecorator::setCostOfIngredient(double)
{
}
/**
 * @brief This method sets the ingredient for the dish.
 *
 * @param ingredient String representing the name of the ingredient to be set.
 */
void DishDecorator::setIngredient(std::string)
{
}
/**
 * @brief This method returns the total cost of the dish.
 *
 * @return Double representing the total cost of the dish.
 */
double DishDecorator::totalCost()
{
    return getCost();
}
/**
 * @brief This method returns a list of ingredients in the dish.
 *
 * @return String representing the list of ingredients in the dish.
 */
std::string DishDecorator::getIngredientsList()
{
    std::string list = component->getIngredientsList();
    return list;
}
/**
 * @brief This method sets the component for the DishDecorator object.
 *
 * @param newComponent Pointer to the Dish object to be set as the component.
 */
void DishDecorator::setComponent(Dish *newComponent)
{
    this->component = newComponent;
    this->setCost(newComponent->getCost());
    this->setIngredientsList(newComponent->getList());
    this->setName(newComponent->getName());
};

DishDecorator::~DishDecorator(){
};
