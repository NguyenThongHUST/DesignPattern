
#ifndef SimplePizzaFactory_hpp
#define SimplePizzaFactory_hpp

#include<string>
#include <vector>
#include <iostream>

using std::string;

class Pizza
{
public:
    string name;
    string dough;
    string sauce;
    std::vector<std::string> toppings;

 /*   const std::string& getName() const;

    virtual void prepare() = 0 ;
    virtual void bake() = 0 ;
    virtual void cut() = 0;
    virtual void box() = 0  ;
    virtual ~Pizza() = default;*/

};


class CheesePizza : public Pizza
{
public:

    CheesePizza() 
    {
        name = "Cheese Pizza";
        dough = "Regular crust";
        sauce = "Marinara Pizza sauce";
        toppings.push_back("Fresh mozzarella");
        toppings.push_back("Parmesan");
    }
    //    void prepare() override;
    //    void bake() override;
    //    void cut() override;
    //    void box() override;

};


class ClamPizza : public Pizza
{
public:

    ClamPizza()
    {
        name = "Clam Pizza";
        dough = "Thin crust";
        sauce = "White garlic sauce";
        toppings.push_back("Clams");
        toppings.push_back("Grated parmesan cheese");
    }
    //    void prepare() override;
    //    void bake() override;
    //    void cut() override;
    //    void box() override;

};

class PepperoniPizza : public Pizza
{
public:

    PepperoniPizza()
    {
        name = "Pepperoni Pizza";
        dough = "Regular crust";
        sauce = "Marinara Pizza sauce";
        toppings.push_back("Sliced pepperoni");
        toppings.push_back("Sliced onion");
        toppings.push_back("Grated parmesan chese");

    }

    //    void prepare() override;
    //    void bake() override;
    //    void cut() override;
    //    void box() override;

};

class VeggiePizza : public Pizza
{
public:

    VeggiePizza()
    {
        name = "Veggie Pizza";
        dough = "Regular crust";
        sauce = "Marinara sauce";
        toppings.push_back("Shredded mozzarella");
        toppings.push_back("Grated Parmesan");
        toppings.push_back("Diced onion");
        toppings.push_back("Sliced mushrooms");
        toppings.push_back("Sliced red pepper");
        toppings.push_back("No olives because they're gross");
    }
    //    void prepare() override;
    //    void bake() override;
    //    void cut() override;
    //    void box() override;

};


#endif
