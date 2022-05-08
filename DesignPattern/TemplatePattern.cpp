
#include<iostream>
#include<string>
#include"TemplatePattern.h"

using namespace std;
using std::string;

int main()
{

	CaffeineBeverage* tea = new Tea();
	CaffeineBeverage* coffe = new Coffe();
	
	tea->prepareRecipe();
	cout << "***********" << endl;
	coffe->prepareRecipe();

	return 0;
}
