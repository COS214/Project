#ifndef SPECIALCOOKINGINSTRUCTIONS_H
#define SPECIALCOOKINGINSTRUCTIONS_H

#include <string>

#include "DishDecorator.h"

using namespace std;

class SpecialCookingInstructions : DishDecorator {

public:
	string instruction;

	void addSpecialInstruction(string instruction);
};

#endif
