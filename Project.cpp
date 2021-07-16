#include <bits/stdc++.h>
// #include "Customer.h"
// #include "psswd.h"
#include "Admin.h"
using namespace std;

void intro()
{
    cout << "\t\t\t\t\t\t     EVERYDAY SUPER MARKET\n\n";
    cout << "\t\t\t\t\t\t\tBILLING SYSTEM";
}

int main()
{
    int ch;
    intro();
    do
    {
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. CUSTOMER";
        cout << "\n\n\t02. ADMINISTRATOR";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            place_order();

            break;
        case 2:

            admin_menu();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "\a";
        }
    } while (ch != 3);
    return 0;
}
