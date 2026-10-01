#include<iostream>

using namespace std;

class Burger
{
    public:
    Burger(){};

    virtual void prepare()=0;
};

class SimpleBurger :public Burger
{
    public:
    SimpleBurger():Burger(){};

    void prepare() override
    {
        cout<<"Preparing the Simple Burger\n";
    }
};

class StdBurger :public Burger
{
    public:
    StdBurger():Burger(){};

    void prepare() override 
    {
        cout<<"Preparig the Standerd Burger\n";
    }
};

class PremiumBurger:public Burger 
{
    public:
    PremiumBurger():Burger(){};
    void prepare() override 
    {
        cout<<"Preparing the Premium Burger\n";
    }
};

class BurgerFactory
{   
    public:
    Burger* prepareBurger(string type)
    {
        if(type=="simple")
        {
            Burger* b=new SimpleBurger();
            b->prepare();
            return b;
        }

        else if(type=="std")
        {
            return new StdBurger();
        }

        else if(type=="premium")
        {
            return new PremiumBurger();
        }

        else
        {
            throw runtime_error("Give A Valid Type\n");
        }
    }
};

int main()
{

    BurgerFactory* f=new BurgerFactory();

    string type="simple";

    Burger* b=f->prepareBurger(type);

    return 0;

}