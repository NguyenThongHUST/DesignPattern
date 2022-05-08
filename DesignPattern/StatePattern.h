
#ifndef StatePattern_hpp
#define StatePattern_hpp

#include<iostream>
#include<string>

using namespace std;
using std::string;

class iState 
{
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
};


class iGumballMachine
{
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void releaseBall() = 0;
	virtual int getCount() = 0;
	virtual int refill() = 0;

	virtual iState* getState() = 0;
	virtual void setState(iState* state) = 0;

	virtual iState* getHasQuarterState() = 0;
	virtual iState* getNoQuarterState() = 0;
	virtual iState* getSoldState() = 0;
	virtual iState* getSoldOutState() = 0;

};

class HasQuarterState: public iState
{
	iGumballMachine* mGumballMachine;
public:
	
	HasQuarterState(iGumballMachine* gumballMachine)
	{
		mGumballMachine = gumballMachine;
	}

	void insertQuarter()
	{
		cout << "You can't insert another quarter" << endl;
		
	}

	void ejectQuarter()
	{
		cout << "Quarter returned" << endl;
		mGumballMachine->setState(mGumballMachine->getNoQuarterState());	
	}

	void turnCrank()
	{
		cout << "You turned..." << endl;
		mGumballMachine->setState(mGumballMachine->getSoldState());
	}

	void dispense()
	{
		cout << "No gumball dispensed" << endl;
	}

	void refill()
	{
		cout << "waiting for turn of crank" << endl;
	}
};


class NoQuarterState : public iState
{
private:
	iGumballMachine* mGumballMachine;
public:
	NoQuarterState(iGumballMachine* gumballMachine)
	{
		mGumballMachine = gumballMachine;
	}

	void insertQuarter()
	{
		cout << "You inserted a quarter" << endl;
		mGumballMachine->setState(mGumballMachine->getHasQuarterState());
	}

	void ejectQuarter()
	{
		cout << "You haven't inserted a quarter" << endl;
	}

	void turnCrank()
	{
		cout << "You turned, but there's no quarter" << endl;
	}

	void dispense()
	{
		cout << "You need to pay first" << endl;
	}

	void refill()
	{
		cout << "waiting for quarter" << endl;
	}

};

class SoldState : public iState
{
private:
	iGumballMachine* mGumballMachine;
public:
	SoldState(iGumballMachine* gumballMachine)
	{
		mGumballMachine = gumballMachine;
	}

	void insertQuarter()
	{
		cout << "Please wait, we're already giving you a gumball" << endl;
	}

	void ejectQuarter() 
	{
		cout << "Sorry, you already turned the crank" << endl;
	}

	void turnCrank()
	{
		cout << "Turning twice doesn't get you another gumball!" << endl;
	}

	void dispense()
	{
		mGumballMachine->releaseBall();
		if (mGumballMachine->getCount() > 0)
		{
			mGumballMachine->setState(mGumballMachine->getNoQuarterState());
		}

		else 
		{
			cout << "Oops, out of gumballs!" << endl;
			mGumballMachine->setState(mGumballMachine->getSoldOutState());
		}
	}

	void refill()
	{
		cout << "dispensing a gumball" << endl;
	}
};

class SoldOutState : public iState
{
	iGumballMachine* mGumballMachine;
public:
	SoldOutState(iGumballMachine* gumballMachine)
	{
		mGumballMachine = gumballMachine;
	}

	void insertQuarter()
	{
		cout << "You can't insert a quarter, the machine is sold out" << endl;
	}

	void ejectQuarter()
	{
		cout << "You can't eject, you haven't inserted a quarter yet" << endl;
	}

	void turnCrank()
	{
		cout << "You turned, but there are no gumballs" << endl;
	}

	void dispense()
	{
		cout << "No gumball dispensed" << endl;
	}

	void refill()
	{
		mGumballMachine->setState(mGumballMachine->getNoQuarterState());
		cout << "No fill" << endl;
	}
};


class GumballMachine: public iGumballMachine
{
public:

	iState* soldOutState;
	iState* noQuarterState;
	iState* hasQuarterState;
	iState* soldState;
	iState* state;

	int mCount;

	GumballMachine(int numberGumballs)
	{
		soldOutState = new SoldOutState(this);
		noQuarterState = new NoQuarterState(this);
		hasQuarterState = new HasQuarterState(this);
		soldState = new SoldState(this);

		mCount = numberGumballs;

		if(numberGumballs>0)
		{
			state = noQuarterState;
		}

		else 
		{
			state = soldOutState;
		}
	}

	void insertQuarter()
	{
		state->insertQuarter();
	}

	void ejectQuarter()
	{
		state->ejectQuarter();
	}

	void turnCrank()
	{
		state->turnCrank();
	}

	void releaseBall()
	{
		cout << "A gumball comes rolling out the slot..." << endl;
		if (mCount > 0) 
		{
			mCount = mCount - 1;
		}
	}

	int getCount() 
	{
		return mCount;
	}

	void refill(int count)
	{
		mCount += count;
		cout << "The gumball machine was just refilled; its new count is: " << mCount << endl;
	}

	void setState(iState* mState)
	{
		state = mState;
	}

	iState* getState()
	{
		return state;
	}

	iState* getSoldOutState()
	{
		return soldOutState;
	}

	iState* getNoQuarterState()
	{
		return noQuarterState;
	}

	iState* getHasQuarterState()
	{
		return hasQuarterState;
	}

	iState* getSoldState()
	{
		return soldState;
	}

};
#endif
