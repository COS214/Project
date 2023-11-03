#ifndef GRILLEDSTRATEGY_H
#define GRILLEDSTRATEGY_H

#include "CookStrategy.h"

class GrilledStrategy : public CookStrategy {

public:
	GrilledStrategy(KitchenOrder* order);
	void cookDish(KitchenOrder* order);
};

#endif
