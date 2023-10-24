#ifndef DISHDECORATOR_H
#define DISHDECORATOR_H

#include "Dish.h"


class DishDecorator : Dish {

public:
	Dish component;

	double totalCost();
};

#endif
