
#ifndef WeatherData_h
#define WeatherData_h

#include<vector>

using std::vector;

class Observer 
{
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject 
{
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
};

class WeatherData : public Subject 
{
private:
	vector<Observer*> observers;
	float temparature;
	float humidity;
	float pressure;

public:
	virtual void registerObserver(Observer* o) override;
	virtual void removeObserver(Observer* o) override;
	virtual void notifyObservers() override;
	
	void measurementsChanged();
	void setMeasurements(float temperature, float humidity, float pressure);

	float getTemperature()
	{
		return temparature;
	}

	float getHumidity()
	{
		return humidity;
	}

	float getPressure()
	{
		return pressure;
	}
};

#endif // !WeatherData_h
