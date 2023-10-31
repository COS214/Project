#ifndef BASICDISH_H
#define BASICDISH_H

#include <iostream>
#include "Dish.h"

class BasicDish : public Dish {
	public:
	
        BasicDish(std::string name);
		double totalCost();
     
};

#endif
