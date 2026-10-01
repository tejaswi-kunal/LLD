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

// this time we also have garlic bread
class Garlic
{
    public:
    virtual void prepare()=0;
};

class SimpleGarlic : public Garlic
{
    public:
    void prepare()
    {
        cout<<"Preparing The Simple Garlic Bread\n";
    }
};

class StdGarlic : public Garlic 
{
    public:
    void prepare()
    {
        cout<<"Preparing The Std Garlic Bread\n";
    }
};

class PremiumGarlic :public Garlic 
{
    public:
    void prepare()
    {
        cout<<"Preparing The Premium Garlic Bread\n";
    }
};


class SimpleWheatGarlic :public Garlic
{
    public:
    void prepare()
    {
        cout<<"Preparing The Simple Wheat Garlic Bread\n";
    }
};

class StdWheatGarlic : public Garlic 
{
    public:
    void prepare()
    {
        cout<<"Preparing The Std Wheat Garlic Bread\n";
    }
};

class PremiumWheatGarlic :public Garlic 
{
    public:
    void prepare()
    {
        cout<<"Preparing The Premium Wheat Garlic Bread\n";
    }
};

class Meal
{
    public:
    Burger *b;
    Garlic *g;

    Meal(Burger *b,Garlic *g)
    {
        this->b=b;
        this->g=g;
    }
};


class BurgerFactory
{
    public:
    virtual Meal* prepareBurger(string &type)=0;
};

class NormalBurgerFactory :public BurgerFactory
{
    public:
    Meal* prepareBurger(string &type) override
    {
        if(type=="simple")
        {
            return new Meal(new SimpleBurger(),new SimpleGarlic());
        }

        else if(type=="std")
        {
            return new Meal(new StdBurger(),new StdGarlic());
        }

        else if(type=="premium")
        {
            return new Meal(new PremiumBurger(),new PremiumGarlic());
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
    Meal* prepareBurger(string &type) override
    {
        if(type=="simple")
        {
            return new Meal(new SimpleWheatBurger(),new SimpleWheatGarlic());
        }

        else if(type=="std")
        {
            return new Meal(new StdWheatBurger(),new StdWheatGarlic());
        }

        else if(type=="premium")
        {
            return new Meal(new PremiumWheatBurger(),new PremiumWheatGarlic());
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
    Meal* m=f->prepareBurger(type);

    m->b->prepare();
    m->g->prepare();
     
    return 0;

}