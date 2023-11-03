#include <list>
#include <iostream>

#include "Dish.h"

	Dish::Dish(){
	}

    void Dish::addIngredient(std::string){
	}

    void Dish::removeIngredient(std::string){
	}

    void Dish::addSpecialInstruction(std::string){
	}

    void Dish::setCostOfIngredient(double){
	}

    void Dish::setIngredient(std::string){
	}

    std::string Dish::getIngredientsList(){
        std::string list= "";
        for (std::string& item : ingredientsForDish) 
        {
            list += item + "\n";
            
        }
        return list;
    }

	
	double Dish::getCost(){
        return cost;
    }

    std::string Dish::getName(){
        return name;
    }
	void Dish::setCost(double cost){
        this->cost = cost;
    };

    void Dish::setName(std::string name){
        this->name = name;
    }

    void Dish::setIngredientsList(const std::list<std::string>& ingredients) {
        this->ingredientsForDish = ingredients;
    }

    std::list<std::string> Dish::getList(){
	    return ingredientsForDish;
    }   
	
	Dish::~Dish() {
	}
