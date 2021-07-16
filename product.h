#include <bits/stdc++.h>
using namespace std;

class product
{
    int pno;
    string name;
    float price, qty, tax, dis;

public:
    product()
    {
        pno = 0;
        name = "";
        price = qty = tax = dis = 0.0;
    }
    void create_product()
    {
        cout << "\nPlease Enter The Product No. of The Product ";
        cin >> pno;
        cout << "\n\nPlease Enter The Name of The Product ";
        cin.ignore();
        getline(cin, name);
        cout << "\nPlease Enter The Price of The Product ";
        cin >> price;
        cout << "\nPlease Enter The Discount (%) ";
        cin >> dis;
    }

    void show_product()
    {
        cout << "\nThe Product No. of The Product : " << pno;
        cout << "\nThe Name of The Product : ";
        cout << name;
        cout << "\nThe Price of The Product : " << price;
        cout << "\nDiscount : " << dis;
    }

    int retpno()
    {
        return pno;
    }

    float retprice()
    {
        return price;
    }

    string retname()
    {
        return name;
    }

    int retdis()
    {
        return dis;
    }
};