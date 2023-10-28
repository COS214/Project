#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "Chefs.h"
#include "Command.h"

class SauceChef : public Chefs {


public:
	void prepareOrder(Command* order) override;
	virtual ~SauceChef()=default;
};

#endif
