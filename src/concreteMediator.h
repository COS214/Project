#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include <string>

#include "Mediator.h"
#include "Chefs.h"
#include "HeadChef.h"
#include "JuniorChef.h"
#include "MeatChef.h"
#include "SauceChef.h"
#include "VegetableChef.h"

using namespace std;

class concreteMediator : Mediator {

public:
	 concreteMediator(Chefs* headChef, Chefs* junior, Chefs* meat, Chefs* sauce, Chefs* veg) 
        : headChef_(headChef), juniorChef_(junior), meatChef_(meat), sauceChef_(sauce), vegChef_(veg) {}
	 void notify(Chefs* sender, std::string event);

private:
	Chefs* headChef_;
    Chefs* juniorChef_;
    Chefs* meatChef_;
    Chefs* sauceChef_;
    Chefs* vegChef_;
};

#endif
