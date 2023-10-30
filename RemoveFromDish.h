#ifndef REMOVEFROMDISH_H
#define REMOVEFROMDISH_H

#include <iostream>
#include "DishDecorator.h"

class RemoveFromDish : public DishDecorator {
	
private:
	std::string ingredient;
    double costOfIngredient;

public:
	RemoveFromDish(std::string name);
	void setIngredient(std::string ingredient);
    void setCostOfIngredient(double costOfIngredient);
	void removeIngredient(std::string ingredient);
	double totalCost();
};


#endif