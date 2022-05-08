

#ifndef StrategyPattern_h
#define StrategyPattern_h

#include<iostream>

// create interface

class QuackBehavior 
{
public:
    virtual void quack() = 0;
    // IN C++: a base class with virtual functions must also have a virtual destructor.
    virtual ~QuackBehavior() = default;
};

class FlyBehavior 
{
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() = default;
};



class Quack : public QuackBehavior 
{
public:
    void quack() override
    {
        std::cout << "Quack" << std::endl;
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() override
    {
        std::cout << "<< Silence >>" << std::endl;
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack() override
    {
        std::cout << "Squeak" << std::endl;
    }
};



class FlyNoWay : public FlyBehavior 
{
public:
    void fly() 
    {
        std::cout << "I can't fly!" << std::endl;
    }
};

class FlyRocketPowered : public FlyBehavior 
{
public:
    void fly() 
    {
        std::cout << "I'm flying with a rocket!" << std::endl;
    }
};

class FlyWithWings : public FlyBehavior 
{
public:
    void fly() 
    {
        std::cout << "I'm flying!" << std::endl;
    }
};


class Duck 
{
    
public:
    std::unique_ptr<FlyBehavior> flyBehavior;
    std::unique_ptr<QuackBehavior> quackBehavior;

    Duck(std::unique_ptr<FlyBehavior> flyBehavior, std::unique_ptr<QuackBehavior> quackBehavior):
        flyBehavior(std::move(flyBehavior)),
        quackBehavior(std::move(quackBehavior))
    {
    }

    virtual ~Duck() = default;

    void performQuack()
    {
        quackBehavior->quack();
    }

    void swim() 
    {
        std::cout << "All ducks float, even decoys!" << std::endl;
    }

    void performFly()
    {
        flyBehavior->fly();
    }

    virtual void display() const = 0;

};

class DecoyDuck : public Duck 
{
public:
    
    DecoyDuck() :
        Duck(std::make_unique<FlyNoWay>(), std::make_unique<MuteQuack>())
    {
    }
    void display() const override
    {
        std::cout << "I'm just a decoy duck" << std::endl;
    }
};

#endif