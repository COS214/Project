#ifndef JUNIORCHEF_H
#define JUNIORCHEF_H

#include "Chefs.h"
#include "Command.h"

class JuniorChef : public Chefs {


public:
	void prepareOrder(Command* order) override;
	virtual ~JuniorChef()=default;
};

#endif
