#ifndef Subject_h
#define Subject_h

#include"Observer.h"

class Observer;
class Subject {
public:
	virtual ~Subject() = default;
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
};


#endif // !Subject_h
