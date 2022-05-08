#ifndef SingletonClass_hpp
#define SingletonClass_hpp

#include<iostream>
#include<string>
#include<vector>

using std::string;

class Singleton 
{
private:
    string mName;
    Singleton(string name) // constructor
    {
        mName = name;
    } 
    static Singleton* instance;
public:
    static Singleton* GetInstance(string name) 
    {
        if(instance == nullptr)
        {
            instance = new Singleton(name);
        }
        return instance;
    }
    string getName()
    {
        return mName;
    }
    string getDescription()
    {
        return "I'm a classic Singleton!";
    }
    ~Singleton() = default;
};

class Singleton2 
{
private:
    string mName;
    static Singleton2 instance;
    Singleton2(string name) 
    {
        mName = name;
    }
    
public:
    static Singleton2& GetInstance() 
    {
        return instance;
    }
    ~Singleton2() = default;
    string getName() 
    {
        return mName;
    }
    string getDescription() 
    {
        return "I'm a classic Singleton!";
    }
};

#endif