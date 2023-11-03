#ifndef DISHDECORATOR_H
#define DISHDECORATOR_H

#include <iostream>
#include "Dish.h"


class DishDecorator : public Dish {
    protected:
        Dish* component;
    public:
        DishDecorator();
        virtual void addIngredient(std::string);
        virtual void removeIngredient(std::string);
        virtual void addSpecialInstruction(std::string);
        virtual void setCostOfIngredient(double);
        virtual void setIngredient(std::string);
        virtual double totalCost();
        virtual std::string getIngredientsList();
        void setComponent(Dish* newComponent);
        virtual ~DishDecorator();
};

#endif
