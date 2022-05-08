
#include<iostream>
#include<string>
#include"AdapterPattern.h"

using std::string;
using namespace std;

int main()
{
    // Test TurkeyAdapter
    Turkey* turkey1 = new WildTurkey();
    TurkeyAdapter* turkey1Adap = new TurkeyAdapter(turkey1);

    turkey1Adap->fly();
    turkey1Adap->quack();

    // Test DuckAdapter
    MallardDuck duck1;
    DuckAdapter duck1Adap(duck1);
    duck1Adap.fly();
    duck1Adap.gobble();
    return 0;
}