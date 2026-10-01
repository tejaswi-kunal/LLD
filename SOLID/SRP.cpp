#include<iostream>

using namespace std;


class Product
{
    public:
    string name;
    int price;

    Product(string name,int price)
    {
        this->name=name;
        this->price=price;
    }
};

class ShoppingCart
{
    private:
    vector<Product>sc;

    public:
    void addProduct(Product &p)
    {
        sc.push_back(p);
        cout<<"Added "<<p.name<<endl;
    }

    void countProducts()
    {
        cout<<"Current Count : "<<sc.size()<<endl;
    }

    void calculatePrice()
    {
        int total=0;

        for(auto it : sc)
        {
            total+=it.price;
        }
        cout<<"Current Total : "<<total<<endl;
    }
};

class StoreToDB
{
    public:
    void saveToDB(ShoppingCart &sc)
    {
        cout<<"...Saving To DB..."<<endl;
    }
};

class PrintInvoice
{
    public:
    void printInvoice(ShoppingCart &sc)
    {
        cout<<"...Printing The Invoivce..."<<endl;
    }
};

int main()
{
    ShoppingCart s;

    Product p1("Apple",50);
    s.addProduct(p1);

    Product p2("Samsung",100);
    s.addProduct(p2);

    s.calculatePrice();
    s.countProducts();

    StoreToDB sdb;
    sdb.saveToDB(s);

    PrintInvoice p;
    p.printInvoice(s);
}