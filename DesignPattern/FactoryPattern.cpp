
#include<string.h>
#include<iostream>
#include <vector>
#include"SimplePizzaFactory.h"

using std::string;
using namespace std;

enum PizzaType
{
	mCheesePizza = 0,
	mClamPizza,
	mPepperoniPizza,
	mVeggiePizza
};

class DbPizzaFactory 
{
public:
	static Pizza* createPizza(PizzaType pizzaType);

};

Pizza* DbPizzaFactory::createPizza(PizzaType pizzaType)
{
	Pizza* create_pizza = nullptr;
	switch (pizzaType)
	{
	case mCheesePizza:
		create_pizza = new CheesePizza();
		break;
	case mClamPizza:
		create_pizza = new ClamPizza();
		break;
	case mPepperoniPizza:
		create_pizza = new PepperoniPizza();
		break;
	case mVeggiePizza:
		create_pizza = new VeggiePizza();
		break;
	default:
		create_pizza = new CheesePizza(); // default is CheesePizza
		break;
	}

	return create_pizza;
}

int main(){
	Pizza* pz;
	DbPizzaFactory dbPizza;
	pz = dbPizza.createPizza(mCheesePizza);
	cout << pz->name << endl;
	
	for (auto tp : pz->toppings)
	{
		cout << tp << endl;
	}
}