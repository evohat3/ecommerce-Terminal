// Programming 3
// main.cpp
// COSC - 2436-002
// Nigel Poblete
// Dr Kevin Roark
// Date: 01/22/2024
/* Description:
   This is a Terminal-Based E-commerce app, when you start the program it will ask
   for your name and the amount you would like to deposit to your wallet. Then you are
   brought to the main menu from which you can view the inventory, your wallet balance,
   your cart and checkout or exit the program. from the view item's inventory you can add
   an item to your cart by typing in the corresponding item # which will then calculate
   your overall balance, with tax and when you checkout it will subtract the balance from 
   your wallet as well as clear the cart.
*/
#include <iostream>
#include <string>
#include "Utility.cpp"
using namespace std;
// Main Program
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
    // Main Menu Switch
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
            viewCart(total, taxAmt, taxRate, choice);
            break;
        case 4:
            // Item Checkout
            itemCheckOut(wallet, total, choice, taxAmt, taxRate);
            break;
        case 0: 
            // Exiting the application
            cout << endl << setfill('-') << setw(30) << "" << endl;
            cout << " Exiting Application, Thank You Hope To See You Again!" << endl;
            cout << endl << setfill('-') << setw(30) << "" << endl;
        default:
            break;
        }
    }
    // End of Program
    return 0;
}