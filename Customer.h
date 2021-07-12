#include <bits/stdc++.h>
#include "product.h"
using namespace std;

fstream fp;
product pr;

void menu()
{
    fp.open("Shop.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
        cout << "\n\n\n Program is closing ....";

        exit(0);
    }

    cout << "\n\n"
         << setw(75) << "Product MENU\n\n";
    cout << "\t\t\t\t"
         << "========================================================================\n";
    cout << setw(50) << "Product No." << setw(25) << "Product Name" << setw(25) << "Price\n";
    cout << "\t\t\t\t"
         << "========================================================================\n";

    while (fp.read((char *)&pr, sizeof(product)))
    {
        cout << setw(50) << pr.retpno() << setw(25) << pr.retname() << setw(25) << pr.retprice() << endl;
    }
    fp.close();
}

void place_order()
{
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';

    cout << "Enter customer's name: ";
    string cust_name;
    cin.ignore();
    getline(cin, cust_name);
    cout << "Enter customer's mobile number: ";
    long long mb_no = 0;
    cin >> mb_no;
    menu();

    cout << "\n============================";
    cout << "\n    PLACE YOUR ORDER";
    cout << "\n============================\n";
    fstream fp2;
    fp2.open("invoice.txt", ios::out | ios::trunc);
    do
    {
        cout << "\n\nEnter The Product No. Of The Product : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;

        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";

    cout << "\n\n\t\t\t********************************INVOICE********************************\n";
    cout << setw(10) << "Pr No." << setw(20) << "Pr Name" << setw(10) << "Qty" << setw(10) << "MRP"
         << setw(10) << "Amount" << setw(15) << "Final Amount";

    fp2 << "\n\n\t\t\t********************************INVOICE********************************\n\n\n";

    fp2 << setw(20) << "Customer Name: " << cust_name << '\n';
    fp2 << setw(20) << "Mobile Number: " << mb_no << "\n\n\n";
    fp2 << setw(10) << "Pr No." << setw(20) << "Pr Name" << setw(10) << "Qty" << setw(10) << "MRP"
        << setw(10) << "Amount" << setw(15) << "Final Amount";
    for (int x = 0; x < c; x++)
    {
        fp.open("Shop.dat", ios::in);
        fp.read((char *)&pr, sizeof(product));
        while (!fp.eof())
        {
            if (pr.retpno() == order_arr[x])
            {
                amt = pr.retprice() * quan[x];
                damt = amt - (amt * pr.retdis() / 100);
                // cout << "\n"
                //      << order_arr[x] << "\t" << pr.retname() << "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
                cout << "\n"
                     << setw(10) << order_arr[x] << setw(20) << pr.retname() << setw(10) << quan[x] << setw(10) << pr.retprice()
                     << setw(10) << amt << setw(10) << damt;
                fp2 << "\n"
                    << setw(10) << order_arr[x] << setw(20) << pr.retname() << setw(10) << quan[x] << setw(10) << pr.retprice()
                    << setw(10) << amt << setw(10) << damt;
                total += damt;
            }
            fp.read((char *)&pr, sizeof(product));
        }

        fp.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total << "\n\n";
    cout << "Please collect Your printable invoice from the .txt file." << endl;
    fp2 << "\n\n\t\t\t\t\tTOTAL = " << total;
}