

#ifndef AdapterPattern_hpp
#define AdapterPattern_hpp

#include<iostream>

using namespace std;
using std::string;

class Duck 
{
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck : public Duck
{
public:
	void quack()
	{
		cout << "Quack" << endl;
	}

	void fly()
	{
		cout << "I'm flying" << endl;
	}
};


class Turkey 
{
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
public:
	void gobble() 
	{
		cout << "Gobble gobble" << endl;
	}
	void fly()
	{
		cout << "I'm flying a short distance" << endl;
	}
};


// Adapter : TurkeyAdapter, DuckAdapter

class TurkeyAdapter : public Duck 
{
private:
	Turkey* mTurkey;
public:
	TurkeyAdapter(Turkey* turkey)
	{
		mTurkey = turkey;
	}

	void quack()
	{
		mTurkey->gobble();
	}

	void fly()
	{
		for (int i = 0; i < 5; i++) 
		{
			mTurkey->fly();
		}
	}
};

class DuckAdapter : public Turkey
{
private:
	MallardDuck mDuck;
public:
	DuckAdapter(MallardDuck duck)
	{
		mDuck = duck;
	}
	void gobble()
	{
		mDuck.quack();
	}

	void fly()
	{
		mDuck.fly();
	}
};

#endif