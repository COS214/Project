#ifndef VEGETABLECHEF_H
#define VEGETABLECHEF_H

#include "Chefs.h"
#include "Command.h"

class VegetableChef : Chefs {


public:
	void prepareOrder(Command order);
};

#endif
