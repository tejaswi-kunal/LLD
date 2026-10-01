// we can follow the lsp using the commmon interface and splitting those interface when we need 
#include<iostream>

using namespace std;

class NonWithdrawable
{
    protected:
    int TotalAmount;

    public:
    NonWithdrawable(int amount)
    {
        this->TotalAmount=amount;
    }

    virtual void deposite(int amount)=0;
    void currentBalance()
    {
        cout<<"Your Current Balance IS "<<TotalAmount<<" $\n";
    }
};

class Withdrawable : public NonWithdrawable
{
    public:
    Withdrawable(int amount):NonWithdrawable(amount){};

    virtual void withdraw(int amount)=0;
};

class SavingAccount : public Withdrawable
{
    public:
    SavingAccount(int amount):Withdrawable(amount){};

    // now we have to override the virtual functions 
    void deposite(int amount) override
    {
        if(amount <=0)
        {
            throw logic_error("Please Enter A Valid Amount\n");
        }
        TotalAmount+=amount;
        cout<<"Succussfully Deposited "<<amount<<"$"<<endl;
    }

    void withdraw(int amount) override
    {
        if(amount<=0)
        {
            throw logic_error("Please Enter A Valid Amount\n");
        }

        else if(amount > TotalAmount)
        {
            throw logic_error("Insufficinet Balance\n");
        }

        else 
        {
            TotalAmount-=amount;
            cout<<"Successfully Withdrawn "<<amount<<"$ \n";
        }
    }
};

class FixedTermAccount :public NonWithdrawable
{
    public:
    FixedTermAccount(int amount):NonWithdrawable(amount){};


    // here we have to only override the deposite function
    void deposite(int amount) override 
    {
        if(amount<=0)
        {
            throw logic_error("Please Enter A Valid Amount\n");
        }

        else
        {
            TotalAmount+=amount;
            cout<<"Successfully Deposited "<<amount<<"$ \n";
        }
    }
};

class Client
{
    private:
    vector<Withdrawable*>wAccounts;
    vector<NonWithdrawable*>nAccounts;

    public:
    Client(vector<Withdrawable*>&wAccounts,vector<NonWithdrawable*>&nAccounts)
    {
        this->nAccounts=nAccounts;
        this->wAccounts=wAccounts;
    }

    // In Each Account we will try to run there functions 
    // for withdrable we will run

    void processTransaction()
    {
        cout<<"Processing Transaction For WithDrawable Accounts:-"<<endl;
        for(auto &it : wAccounts)
        {
            it->deposite(500);
            it->withdraw(100);
            it->currentBalance();
        }

        cout<<"Proccessing Transaction For Non Withdrawable Accounts:- "<<endl;
        for(auto &it : nAccounts)
        {
            it->deposite(500);
            it->currentBalance();
        }
    }
};

int main()
{
    vector<Withdrawable*>accounts1;
    vector<NonWithdrawable*>accounts2;

    accounts1.push_back(new SavingAccount(400));
    accounts2.push_back(new FixedTermAccount(500));

    Client* c= new Client(accounts1,accounts2);
    c->processTransaction();

    return 0;
}
