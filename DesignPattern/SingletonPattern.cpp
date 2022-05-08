
#include<string.h>
#include<iostream>
#include<vector>
#include"SingletonClass.h"


using std::string;
using namespace std;

// static
Singleton* Singleton::instance = nullptr;


int main() 
{
	/*using Singleton using pointer*/
	Singleton* sg;
	sg = Singleton::GetInstance("thong");
	Singleton::GetInstance("thuc");
	cout << sg->getName() << endl;
	cout << sg->getDescription() << endl;
	/*using reference*/
	
}