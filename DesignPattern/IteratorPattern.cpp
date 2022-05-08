
#include<iostream>
#include<string>
#include"IteratorPattern.h"

using namespace std;
using std::string;

int main()
{
    PancakeMenu *pancakeMenu = new PancakeMenu();
    DinerMenu *dinerMenu = new DinerMenu();
    Waitress *waitress =new Waitress(pancakeMenu, dinerMenu);
    waitress->printMenu();

}