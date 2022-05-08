
#include<iostream>
#include<string>
#include"StatePattern.h"

using namespace std;
using std::string;

int main()
{
	int count = 5;
	iGumballMachine* gumballMachine;
	gumballMachine = new GumballMachine(5);

	gumballMachine->insertQuarter();
	gumballMachine->ejectQuarter();
	gumballMachine->turnCrank();

	cout << gumballMachine << endl;
	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	gumballMachine->ejectQuarter();

}