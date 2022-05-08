
#include<string.h>
#include<iostream>
#include <vector>


using std::string;
using namespace std;

class Printable 
{
public:
	virtual string GetName() = 0;
};

class A:public Printable
{
public:
	string GetName() override { return "Entity"; }
};



class IObserver {
public:
	virtual void update(string operation, string record) = 0;
};

class ISubject {
public:
	virtual void registerObserver(IObserver *o) = 0;
	virtual void removeObserver(IObserver* o) = 0;
	virtual void notifyObservers() = 0;
};

class Database : public ISubject {
private:
	vector<class IObserver*> mObservers;
	string mOperation;
	string mRecord;
public:
	void registerObserver(IObserver* o) 
	{
		mObservers.push_back(o);
	}

	void removeObserver(IObserver*o)
	{
		auto observer = find(mObservers.begin(), mObservers.end(), o);
		if (observer != mObservers.end()) {
			mObservers.erase(observer, observer + 1); // remove observer from mObservers
		}
	}

	void notifyObservers() 
	{
		for (auto& o : mObservers) 
		{
			o->update(mOperation, mRecord);
		}
	}

	void editRecord(string operation, string record) 
	{
		mOperation = operation;
		mRecord = record;
		notifyObservers();
	}
};

class Client : public IObserver
{
public:
	Client() {}

	void update(string operation, string record) {
		cout << "Client: " << operation << " opeation was performed on " << record << endl;
	}
};

class Developer : public IObserver
{
public:
	Developer() {}

	void update(string operation, string record) {
		cout << "Developer: " << operation << " opeation was performed on " << record << endl;
	}
};

class Boss : public IObserver
{
public:
	Boss() {}

	void update(string operation, string record) {
		cout << "Boss: " << operation << " opeation was performed on " << record << endl;
	}
};

class Pet {
	protected:
		string Name;
	public:
		Pet(string name) {
			Name = name;
		}
		virtual string getSound() = 0;
		void makeSound(){
			cout << Name << " says: " << getSound() << endl;
		}
};

class Dog : public Pet {
	public:
		Dog(string name) : Pet(name){}
		string getSound(){
			return "Woof!Woof!";
		}
};

class Cat : public Pet {
	public:
		Cat(string name) : Pet(name){}
		string getSound() {
			return "Meow!Meow!";
		}
};


// factory design pattern

// define enum type for connection types
enum eConnectionType
{
	CONNECTION_TYPE_ORACLE = 0,
	CONNECTION_TYPE_SQLSERVER,
	CONNECTION_TYPE_MYSQL,
	CONNECTION_TYPE_DEFAULT
};

class Connection {
public:
	virtual string description() = 0;
	/*virtual void setDbName(string dbName) = 0;
	virtual void setUsername(string username) = 0;
	virtual void setPassword(string password) = 0;
	virtual bool initialize() = 0;*/
};


class OracleConnection : public Connection
{
public:
	// implemement Connection's interfaces
	string description()
	{
		return "OracleConnection";
	};
};

class SqlServerConnection : public Connection
{
public:
	// implemement Connection's interfaces
	string description()
	{
		return "SqlServerConnection";
	};
};

class MySqlConnection : public Connection
{
public:
	// implemement Connection's interfaces
	string description()
	{
		return "MySqlConnection";
	};
};


class DbConnectionFactory
{
public:
	static Connection* createConnection(eConnectionType connectionType);
};

Connection* DbConnectionFactory::createConnection(eConnectionType connectionType)
{
	Connection* connection = nullptr;

	switch (connectionType)
	{
	case CONNECTION_TYPE_ORACLE:
		connection = new OracleConnection();
		break;
	case CONNECTION_TYPE_SQLSERVER:
		connection = new SqlServerConnection();
		break;
	case CONNECTION_TYPE_MYSQL:
		connection = new MySqlConnection();
		break;
	default:
		connection = new OracleConnection(); // default is Oracle
		break;
	}

	return connection;
}



// factory design pattern c++

enum ProductId {
	YOUR_ID = 0,
	MY_ID
};

class Product {
	public:
		virtual string description() = 0;
};

class MyProduct : public Product {
	public:
		string description() {
			return "MyProduct!";
		}
};


class YourProduct : public Product {
	public:
		string description() {
			return "Your Product!";
		}

};

class Creator {
	public:
		virtual Product* Create(ProductId ID);
};

Product* Creator::Create(ProductId ID) {
	Product* product = nullptr;
	switch (ID)
	{
		case YOUR_ID: 
			product = new YourProduct();
			break;
		case MY_ID:
			product = new MyProduct();
			break;
	}

	return product;
}

/* Abstract design pattern*/



int main()
{
	
	/*Database database;
	Client client;
	Boss boss;
	database.registerObserver(&client);
	database.registerObserver(&boss);
	database.removeObserver(&boss);
	database.editRecord("delete", "record1");*/

	//Connection* connection;
	//DbConnectionFactory database;

	//connection = database.createConnection(CONNECTION_TYPE_SQLSERVER);

	//cout << connection->description() << endl;

	Product* pd;
	Creator c;
	pd = c.Create(MY_ID);
	cout << pd->description() << endl;

	return 0;
}