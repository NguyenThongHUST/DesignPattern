#include<iostream>
#include<string>


using std::string;
using namespace std;

class Database
{
private:
    static Database* mInstancePtr;
    int mRecord;
    string mName;

    Database(string name)
    {
        mName = name;
        mRecord = 0;
    }

public:

    void editRecord(string operation)
    {
        cout << "Performing a " << operation <<
            "operation on record " << mRecord <<
            " in database " << mName << endl;
    }

    string getName()
    {
        return mName;
    }

    static Database* getInstance(string name)
    {
        if (mInstancePtr == nullptr)
        {
            mInstancePtr = new Database(name);
        }
        return mInstancePtr;
    }
};

Database* Database::mInstancePtr = nullptr;

int main() {
    Database* db1;
    db1 = Database::getInstance("thong");
    cout << "This is the " << db1->getName() << " database." << endl;
    db1 = Database::getInstance("thuc");
    cout << "This is the " << db1->getName() << " database." << endl;
}