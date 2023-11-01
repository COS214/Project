#include "FriedStrategy.h"

FriedStrategy::FriedStrategy(KitchenOrder* order) {
	order->setState("Cooking");
}

void FriedStrategy::cookDish(KitchenOrder* order) {
	order->setState("Fried");
	std::cout << "Meat is being fried" << std::endl;
}
