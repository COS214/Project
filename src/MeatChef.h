#ifndef MEATCHEF_H
#define MEATCHEF_H

#include "Chefs.h"
#include "Command.h"
#include "CookStrategy.h"

class MeatChef : public Chefs {

public:
	CookStrategy* cookStrategy;

	void prepareOrder(Command* order) override;
	virtual ~MeatChef()=default;
};

#endif
