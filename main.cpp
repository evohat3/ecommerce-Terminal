// Programming 3
// main.cpp
// COSC - 2436-002
// Nigel Poblete
// Dr Kevin Roark
// Date:
/* Description:
   A Program that will
*/
#include <iostream>
#include <string>
#include "Utility.cpp"
using namespace std;

int main() {
    int choice = -1;
    string name = "";
    double wallet = 0;
    int itemNum = 0 ;
    double total = 0;
    double taxRate = 0.0825;
    double taxAmt =  0;
    // Intro
    menuHeader(name, wallet);
    while (choice !=0)
    {
        // Main Menu
        mainMenu(choice);
        // Main Menu options
        switch (choice)
        {
        case 1:
            // Views Inventory
            viewInventory(itemNum, total, taxAmt, taxRate);
            break;
        case 2:
            // Views Account Balance
            viewAccount(name, wallet, choice);
            break;
        case 3:
            // Views Cart Information
            viewCart(total, taxAmt, taxRate);
            break;
        case 4:
            // Item Checkout
            itemCheckOut(wallet, total, choice, taxAmt, taxRate);
            break;
        case 0: 
            cout << " Exiting Application, Thank You Hope To See You Again!" << endl;
        default:
            cout << "Invalid Selection Please Try Again" << endl;
        }
    }
    // End of Program
    return 0;
}