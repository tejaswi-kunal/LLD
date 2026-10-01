#include<iostream>

using namespace std;

class Account
{
    protected:
    int totalAmount;

    public:
    Account(int amount)
    {
        this->totalAmount=amount;
    }

    virtual void deposite(int amount)=0;
    virtual void withdraw(int amount)=0;
    virtual void currentAmount()=0;

};

class SavingAccount : public Account
{
    public:
    SavingAccount(int amount):Account(amount){};

    void deposite(int amount) override
    {
        this->totalAmount+=amount;
        cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
    }

    void withdraw(int amount) override 
    {
        if(amount>this->totalAmount)
        {
            throw logic_error("Insufficient Balance\n");
        }

        else if(amount<=0)
        {
            throw invalid_argument("Please Enter A Valid Amount\n");
        }

        else
        {
            cout<<"Amount "<<amount<<"$ Withdrawn Succesfully"<<endl;
            this->totalAmount-=amount;
            cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
        }
    }

    void currentAmount() override 
    {
        cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
    }
};

class CurrentAccount : public Account
{
    public:
    CurrentAccount(int amount):Account(amount){};

    void deposite(int amount) override
    {
        this->totalAmount+=amount;
        cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
    }

    void withdraw(int amount) override 
    {
        if(amount>this->totalAmount)
        {
            throw logic_error("Insufficient Balance\n");
        }

        else if(amount<=0)
        {
            throw invalid_argument("Please Enter A Valid Amount\n");
        }

        else
        {
            cout<<"Amount "<<amount<<"$ Withdrawn Succesfully"<<endl;
            this->totalAmount-=amount;
            cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
        }
    }

    void currentAmount() override 
    {
        cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
    }
};

class FixedAccount : public Account{
    public:
    FixedAccount(int amount):Account(amount){};

    // now we have to override the two functions 
    void deposite(int amount) override
    {
        this->totalAmount+=amount;
        cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
    }

    void withdraw(int amount) override{
        throw logic_error("Fixed Account Doesnt Suppert Withdraw\n");
    }

    void currentAmount() override 
    {
        cout<<"Current Balance : "<<this->totalAmount<<"$"<<endl;
    }
};

class Client
{
    // a client can have multiple accounts
    vector<Account*>accounts;

    public:
    Client(vector<Account*>accounts)
    {
        this->accounts=accounts;
    }

    // for test case we are depositing ,withdrawing amount adn at last prining the current amount
    void process_transaction()
    {
        // deposite 1000 to all
        for(auto it : accounts)
        {
            it->deposite(1000);
        }

        // withdraw 500 from all
        for(auto it : accounts)
        {
            it->withdraw(500);
        }
    }
};


int main()
{
    vector<Account*>accounts;

    accounts.push_back(new SavingAccount(500));
    accounts.push_back(new CurrentAccount(200));
    accounts.push_back(new FixedAccount(300));

    Client* c=new Client(accounts);

    try{
    c->process_transaction();
    }catch(logic_error &e)
    {
        cout<<"Exception Error : "<<e.what()<<endl;
    }


}
