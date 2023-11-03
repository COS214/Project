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
	Dish();
    virtual void addIngredient(std::string);
    virtual void removeIngredient(std::string);
    virtual void addSpecialInstruction(std::string);
    virtual void setCostOfIngredient(double);
    virtual void setIngredient(std::string);
    virtual std::string getIngredientsList();
	virtual double totalCost()=0;
	virtual double getCost();
    std::string getName();
	virtual void setCost(double cost);
    void setName(std::string name);
    void setIngredientsList(const std::list<std::string>& ingredients);
    std::list<std::string> getList();
	virtual ~Dish();
};


#endif


