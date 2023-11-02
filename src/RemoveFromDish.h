#ifndef REMOVEFROMDISH_H
#define REMOVEFROMDISH_H

#include <string>

#include "DishDecorator.h"

using namespace std;

class RemoveFromDish : DishDecorator {

public:
	string ingredient;

	void removeIngredient(string ingredient);
};

#endif
