#include "GrilledStrategy.h"

GrilledStrategy::GrilledStrategy(KitchenOrder* order) {
	order->setState("Cooking");
}

void GrilledStrategy::cookDish(KitchenOrder* order) {
	order->setState("Grilled");
	std::cout << "Meat is being grilled" << std::endl;
}
