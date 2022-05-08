
#ifndef TemplatePattern_hpp
#define TemplatePattern_hpp

#include<iostream>
#include<string>

using std::string;
using namespace std;

class CaffeineBeverage
{
public:
	void prepareRecipe() 
	{
		boilWater();
		brew();
		pourInCup();
		addCondiments();
	}

	virtual void boilWater()
	{
		cout << "boiling water" << endl;
	}

	virtual void brew()
	{
		cout << "brewing thing" << endl;
	}

	virtual void pourInCup()
	{
		cout << "pour in cup" << endl;
	}

	virtual void addCondiments()
	{
		cout << "add condiments" << endl;
	}
};

class Coffe : public CaffeineBeverage
{
public:
	void brew()
	{
		cout << "Dripping Coffee through filter" << endl;
	}

	void addCondiments()
	{
		cout << "Adding Sugar and Milk" << endl;
	}
};

class Tea : public CaffeineBeverage
{
public:
	void brew() 
	{
		cout << "Steeping the tea" << endl;
	}
	
	void addCondiments() {
		cout << "Adding Lemon" << endl;
	}
};


#endif