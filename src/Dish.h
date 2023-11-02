#ifndef DISH_H
#define DISH_H

#include <iostream>
#include <list>

class Dish {

protected:
	std::string name;
	int id;
	double cost;
	std::list<std::string> ingredientsForDish;

public:
	Dish(std::string name);
    std::string getIngredientsList();
	virtual double totalCost()=0;
	double getCost();
	void setCost(double cost);
	virtual ~Dish();
};

#endif


