
#include<string>
#include<iostream>
#include"DecoratorPattern.h"

using std::string;
using namespace std;


int main() 
{
	Beverage* beveragePtr;
	beveragePtr = new Espresso();
	beveragePtr = new Milk(beveragePtr);
	beveragePtr = new Mocha(beveragePtr);

	cout << beveragePtr->getDescription()<< endl;

	return 0;
}