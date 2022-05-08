
#include<iostream>
#include<string.h>
#include<vector>
#include"ObserverPattern.h"

using std::vector;
using namespace std;


void WeatherData::registerObserver(Observer* o)
{
	observers.push_back(o);
}

void WeatherData::removeObserver(Observer* o)
{
	auto observer = find(observers.begin(), observers.end(), o);
	if (observer != observers.end()) {
		observers.erase(observer, observer + 1); // remove observer from mObservers
	}
}

void WeatherData::notifyObservers()
{
	for(auto &o : observers)
	{
		o->update(temparature, humidity, pressure);
	}
}

void WeatherData::setMeasurements(float temp, float h, float p)
{
	temparature = temp;
	humidity = h;
	pressure = p;
	measurementsChanged();
}

void WeatherData::measurementsChanged()
{
	notifyObservers();
}

/* 1 class observer*/

class Supervisor : public Observer 
{
	public:
		Supervisor(){}
		
		void update(float temp, float humidity, float pressure)
		{
			cout << "***Supervisor***" << endl;
			cout << "Temp:" << temp << " Humidity: " << humidity << " Pressure:" << pressure << endl;
		}
};

class Client : public Observer
{
	public:
		Client(){}
		void update(float temp, float humidity, float pressure)
		{
			cout << "***Client***" << endl;
			cout << "Temp:" << temp << " Humidity: " << humidity << " Pressure:" << pressure << endl;
		}
};

int main() 
{
	Supervisor sp1;
	Client client;
	WeatherData wd;
	wd.registerObserver(&sp1);
	wd.registerObserver(&client);
	wd.removeObserver(&client);
	wd.setMeasurements(25, 60, 10);

}


