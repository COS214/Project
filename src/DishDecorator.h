#ifndef DISHDECORATOR_H
#define DISHDECORATOR_H

#include <iostream>
#include "Dish.h"


class DishDecorator : public Dish {
    protected:
        Dish* component;
    public:
        DishDecorator(std::string name);
        virtual double totalCost();
        virtual ~DishDecorator();
};

#endif
