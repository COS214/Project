#ifndef COOKSTRATEGY_H
#define COOKSTRATEGY_H

#include "KitchenOrder.h"

class CookStrategy {

public:
	virtual void cookDish(KitchenOrder* order) = 0;
};

#endif
