
#ifndef DecoratorPattern_hpp
#define DecoratorPattern_hpp

#include<string>
#include <vector>
#include <iostream>
#include <memory>

using std::string;

// superclass : Beverage 
class Beverage 
{
    // pure abstract class!
public:
    
    virtual string getDescription() 
    {
        return "no beverage";
    }

    virtual double cost()
    {
        return 0;
    }
};

// subclass : DarkRoast, Decaf, Espresso
class DarkRoast : public Beverage 
{
public:
    string getDescription()  
    {
        return "Dark Roast Coffee";
    }

    double cost() 
    {
        return 0.99;
    }
};

class Decaf : public Beverage
{
public:
    string getDescription() 
    {
        return "Decaf Coffee";
    }

    double cost() 
    {
        return 1.05;
    }
};

class Espresso : public Beverage
{
public:
    string getDescription()  
    {
        return "Espresso Coffee";
    }

    double cost() override 
    {
        return 1.99;
    }
};

class HouseBlend : public Beverage
{
public:
    std::string getDescription() 
    {
        return "House Blend Coffee";
    }

    double cost() 
    {
        return 0.89;
    }
};



class CondimentDecorator : public Beverage
{
public:
    virtual string getDiscription()
    {
        return "";
    }
};

class Milk : public CondimentDecorator
{
public:
    Beverage* mBeverage;
    Milk(Beverage* beverage)
    {
        mBeverage = beverage;
    }
    string getDescription()
    {
        return  mBeverage->getDescription() + " milk";
    }
    double cost()
    {
        return mBeverage->cost() + 2.5;
    }
};

class Mocha : public CondimentDecorator
{
public:
    Beverage* mBeverage;
    Mocha(Beverage* beverage)
    {
        mBeverage = beverage;
    }
    string getDescription()
    {
        return  mBeverage->getDescription() + " mocha";
    }

    double cost()
    {
        return mBeverage->cost() + 1.5;
    }
};

#endif