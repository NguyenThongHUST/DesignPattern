
#ifndef Observer_h
#define Observer_h

class Observer{
public:
	virtual ~Observer() = default;
	virtual void update(float temp, float humidity, float pressure) = 0;
};

#endif 
