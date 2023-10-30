#include <iostream>
#include "DishDecorator.h"

DishDecorator::DishDecorator(std::string name):Dish(name){

}

double DishDecorator::totalCost(){
	return getCost();
};

DishDecorator::~DishDecorator(){

};



