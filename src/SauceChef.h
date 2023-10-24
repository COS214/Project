#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "Chefs.h"
#include "Command.h"

class SauceChef : Chefs {


public:
	void prepareOrder(Command order);
};

#endif
