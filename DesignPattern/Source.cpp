
#include<stdio.h>
#include<string>
#include<mutex>
#include<iostream>

using std::string;
using namespace std;

class Database 
{
private:
	int mRecord;
	string mName;
	static mutex mLocker;

	static Database* mInstancePtr;
	Database(string name)
	{
		mName = name;
		mRecord = 0;
	}

public:

	void editRecord(string operation) 
	{
		std:: cout << "Performing a " << operation <<
			"operation on record " << mRecord <<
			" in database " << mName << std::endl;
	}

	string getName()
	{
		return mName;
	}
	static Database* getInstance(string name)
	{
		mLocker.lock();
		if (mInstancePtr == nullptr) 
		{
			mInstancePtr = new Database("products");
		}
		mLocker.unlock();
		return mInstancePtr;
	}
};

// initilize static
Database* Database::mInstancePtr = nullptr;
mutex Database::mLocker;


struct Entity 
{
	static int x, y;
	static void Print()
	{
		cout << x << endl;
		cout << y << endl;
	}
};

int Entity::x;
int Entity::y;

int main() 
{
	/*Database* database;
	database = Database::getInstance("products");
	cout << "This is the " << database->getName() << " database." << endl;
	database = Database::getInstance("employees");
	cout << "This is the " << database->getName() << " database." << endl;
	return 0;*/

	char name[20];
	printf("Enter your name:");
	gets(name);

}