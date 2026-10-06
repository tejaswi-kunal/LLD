#include<iostream>

using namespace std;

class Singleton
{
    private:
    static Singleton* instance;
    Singleton()
    {

    }

    // we have to also delete the copy constructor and assignment operator
    Singleton(const Singleton&)=delete;
    Singleton &operator=(const Singleton&)=delete;

    public:
    // now for the creation of new object we will use the static method
    static Singleton* getInstance()
    {
        if(instance==nullptr)
        {
            instance=new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance=nullptr;

int main()
{
    Singleton* s1=Singleton::getInstance();
    Singleton* s2=Singleton::getInstance();

    if(s1==s2)
    {
        cout<<true;
    }

    else
    {
        cout<<false;
    }
    return 0;
}