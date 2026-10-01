#include<iostream>

using namespace std;

class Burger
{
    public:
    virtual void prepare()=0;
};

class SimpleBurger : public Burger
{
    public:
    void prepare() override 
    {
        cout<<"Preparing The Simple Burger\n";
    }
};

class StdBurger : public Burger
{
    public:
    void prepare() override
    {
        cout<<"Preparing The Std Burger\n";
    }
};

class PremiumBurger : public Burger
{
    public:
    void prepare() override
    {   
        cout<<"Preapring The Premium Burger\n";
    }
};

class SimpleWheatBurger : public Burger
{
    public:
    void prepare() override 
    {
        cout<<"Preparing The Simple Wheat Burger\n";
    }
};

class StdWheatBurger : public Burger
{
    public:
    void prepare() override 
    {
        cout<<"Preparing The Std Wheat Burger\n";
    }
};

class PremiumWheatBurger : public Burger
{
    public:
    void prepare() override 
    {
        cout<<"Preparing The Premium Wheat Burger\n";
    }
};


class BurgerFactory
{
    public:
    virtual Burger* prepareBurger(string &type)=0;
};

class NormalBurgerFactory :public BurgerFactory
{
    public:
    Burger* prepareBurger(string &type) override
    {
        if(type=="simple")
        {
            Burger *b=new SimpleBurger();
            b->prepare();
            return b;
        }

        else if(type=="std")
        {
            Burger* b=new StdBurger();
            b->prepare();
            return b;
        }

        else if(type=="premium")
        {
            Burger* b=new PremiumBurger();
            b->prepare();
            return b;
        }

        else
        {
            throw runtime_error("Please Enter A Valid Type");
        }
    }
};

class WheatBurgerFactory :public BurgerFactory
{
    public:
    Burger* prepareBurger(string &type) override
    {
        if(type=="simple")
        {
            Burger *b=new SimpleWheatBurger();
            b->prepare();
            return b;
        }

        else if(type=="std")
        {
            Burger* b=new StdWheatBurger();
            b->prepare();
            return b;
        }

        else if(type=="premium")
        {
            Burger* b=new PremiumWheatBurger();
            b->prepare();
            return b;
        }

        else
        {
            throw runtime_error("Please Enter A Valid Type");
        }
    }
};



int main()
{
    string type = "simple";

    BurgerFactory* f=new WheatBurgerFactory();
    Burger* b=f->prepareBurger(type);
     
    return 0;

}