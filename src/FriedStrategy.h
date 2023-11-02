#ifndef FRIEDSTRATEGY_H
#define FRIEDSTRATEGY_H

#include "CookStrategy.h"

class FriedStrategy : public CookStrategy {

public:
	FriedStrategy(KitchenOrder* order);
	void cookDish(KitchenOrder* order);
};

#endif
