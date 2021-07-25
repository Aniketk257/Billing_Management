#include <bits/stdc++.h>
#include "psswd.h"
#include "Customer.h"
using namespace std;

int count = 0;
void delete_product()
{
    int no;
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin >> no;
    fp.open("Shop.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&pr, sizeof(product)))
    {
        if (pr.retpno() != no)
        {
            fp2.write((char *)&pr, sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat", "Shop.dat");
    cout << "\n\n\tRecord Deleted ..";
}

void modify_product()
{
    int no, found = 0;
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tPlease Enter The Product No. of The Product";
    cin >> no;
    fp.open("Shop.dat", ios::in | ios::out);
    while (fp.read((char *)&pr, sizeof(product)) && found == 0)
    {
        if (pr.retpno() == no)
        {
            pr.show_product();
            cout << "\nPlease Enter The New Details of Product" << endl;
            pr.create_product();
            int pos = -1 * sizeof(pr);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&pr, sizeof(product));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
}

void write_product()
{
    fp.open("Shop.dat", ios::out | ios::app);
    pr.create_product();
    fp.write((char *)&pr, sizeof(product));
    fp.close();
    cout << "\n\nThe Product Has Been Created ";
}

void display_all()
{
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("Shop.dat", ios::in);
    while (fp.read((char *)&pr, sizeof(product)))
    {
        pr.show_product();
        cout << "\n\n====================================\n";
    }
    fp.close();
}

void display_sp(int n)
{
    int flag = 0;
    fp.open("Shop.dat", ios::in);
    while (fp.read((char *)&pr, sizeof(product)))
    {
        if (pr.retpno() == n)
        {
            pr.show_product();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nrecord not exist";
}

void admin_menu()
{
    int inp = 1;
    if (::count == 0)
    {
        inp = takePasswdFromUser();
        ::count++;
    }
    if (inp == 1)
    {
        int ch2;
        cout << "\n\n\n\tADMIN MENU";
        cout << "\n\n\t1.CREATE PRODUCT";
        cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
        cout << "\n\n\t3.QUERY ";
        cout << "\n\n\t4.MODIFY PRODUCT";
        cout << "\n\n\t5.DELETE PRODUCT";
        cout << "\n\n\t6.VIEW PRODUCT MENU";
        cout << "\n\n\t7.BACK TO MAIN MENU";
        cout << "\n\n\tPlease Enter Your Choice (1-7) ";
        cin >> ch2;

        switch (ch2)
        {
        case 1:
            write_product();
            break;
        case 2:
            display_all();
            break;
        case 3:
            int num;
            cout << "\n\n\tPlease Enter The Product No. ";
            cin >> num;
            display_sp(num);
            break;
        case 4:
            modify_product();
            break;
        case 5:
            delete_product();
            break;
        case 6:
            menu();

        case 7:
            break;
        default:
            cout << "\a";
            admin_menu();
        }
    }
    else
    {
        cout << "Incorrect Password" << endl;
        exit(0);
    }
}