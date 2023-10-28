#ifndef ADDTODISH_H
#define ADDTODISH_H

#include <string>

#include "DishDecorator.h"

using namespace std;

class AddToDish : DishDecorator {

private:
	string ingredient;
	double costOfIngredient;

public:
	void addIngredient(string ingredient);

	double totalCost();
};

#endif
