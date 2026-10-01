#include<iostream>

using namespace std;


class TalkAble
{
    public:
    virtual void talk()=0;
};

class FlyAble
{
    public:
    virtual void fly()=0;
};

class WalkAble
{
    public:
    virtual void walk()=0;
};

class NormalTalk : public TalkAble
{
    public:
    void talk() override
    {
        cout<<"Robot Can Talk Normally\n";
    }
};

class NonTalk : public TalkAble
{
    public:
    void talk() override 
    {
        cout<<"Robot Cannot Talk\n";
    }
};

class NormalFly : public FlyAble
{
    public:
    void fly() override 
    {
        cout<<"Robot Can Fly Normally\n";
    } 
};

class NonFly : public FlyAble
{
    public:
    void fly() override 
    {
        cout<<"Robot Cannot Fly\n";
    }
};

class NormalWalk : public WalkAble
{
    public:
    void walk() override
    {
        cout<<"Robot Can Walk Normally\n";
    }
};

class NonWalk : public WalkAble
{
    public:
    void walk() override 
    {
        cout<<"Robot Cannot Walk Normally\n";
    }
};


class Robot
{
    private:
    TalkAble* t;
    FlyAble* f;
    WalkAble* w;

    public:
    Robot(TalkAble* t,FlyAble* f,WalkAble* w)
    {
        this->f=f;
        this->t=t;
        this->w=w;
    }

    void simulate()
    {
        t->talk();
        f->fly();
        w->walk();
    }
};


// now we can make diffrent combinations at the runtime 
int main()
{
    Robot* r1=new Robot(new NormalTalk(),new NonFly(),new NormalWalk());
    r1->simulate();
}
