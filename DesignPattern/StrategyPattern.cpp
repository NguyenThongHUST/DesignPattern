
#include<string.h>
#include<iostream>
#include <vector>
#include"StrategyPattern.h"

using std::string;
using namespace std;

int main()
{

    DecoyDuck decoy;
    decoy.display();
    decoy.swim();
    decoy.performQuack();
    decoy.performFly();

}