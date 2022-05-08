
#include <iostream>
#include <string>
#include <memory>

using std::string;
using namespace std;

class Test {
private:
    int mX;
public:
    Test() { std::cout << "Test's constructor" << std::endl; }
    ~Test() { std::cout << "Test's destructor" << std::endl; }

    void setX(int x) 
    { 
        mX = x; 
    }

    int getX() 
    { 
        return mX; 
    }
};

int main()
{
    std::unique_ptr<Test> ptr = std::make_unique <Test>();
    std::unique_ptr<Test> ptr1 = std::move(ptr);
    ptr1->setX(10);
    std::cout << ptr1->getX() << endl;
    return 0;
}
