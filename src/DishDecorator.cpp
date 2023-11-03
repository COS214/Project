#include <iostream>
#include "DishDecorator.h"

DishDecorator::DishDecorator() {
}

void DishDecorator::addIngredient(std::string){
}

void DishDecorator::removeIngredient(std::string){
}

void DishDecorator::addSpecialInstruction(std::string){
}

void DishDecorator::setCostOfIngredient(double){
}

void DishDecorator::setIngredient(std::string){
}

double DishDecorator::totalCost(){
    return getCost();
}

std::string DishDecorator::getIngredientsList() {
    std::string list = component->getIngredientsList();
    return list;
}

void DishDecorator::setComponent(Dish* newComponent){
    this->component = newComponent;
    this->setCost(newComponent->getCost());
    this->setIngredientsList(newComponent->getList());
    this->setName(newComponent->getName());
};

DishDecorator::~DishDecorator() {

};



