// Programming 3
// Utility.cpp
// COSC - 2436-002
// Nigel Poblete
// Dr Kevin Roark
// Date:
// Description:
// The Header Definition file

#include "Utility.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>    
using namespace std;

// **** Items Struct
struct Items {
    string name;
    double price;
    string url;
    string category;
};
// **** Items Data
vector<Items> inventory = {
    {"Zinus Queen Bed Frame", 129.99, "https://www.amazon.com/dp/B0DLP245LL", "Home"},
    {"Huuger TV Stand Dresser",129.99,"https://www.amazon.com/dp/B0DLP245LL", "Home"},
    {"Shark Robot Vacuum", 799.99, "https://www.amazon.com/dp/B0DCPX2M8N/", "Home"},
    {"Master Cook 3 BBQ Grill", 198.99, "https://www.amazon.com/dp/B082HG76CB", "Garden" },
    {"Keter Outdoor Storage Box", 195.29, "https://www.amazon.com/dp/B01HDPY7RG", "Garden"},
    {"Remote Control Lawn Mower", 7994.00, "https://www.amazon.com/dp/B0D9VT69WZ/", "Garden"},
    {"ASUS X870 Motherboard", 249.99, "https://www.amazon.com/dp/B0DGB8Q19Y", "Electronics"},
    {"Seagate 24TB Ext HDD", 459.95, "https://www.amazon.com/dp/B0CMV9Q5MT", "Electronics"},
    {"Elegoo 3pc ESP-32", 19.99, "https://www.amazon.com/dp/B0D8T53CQ5", "Electronics"}
};
//  **** Cart Data
vector<Items> cart;
// **** functions Section ****
    // This function is the Intro Header
void menuHeader(string& name, double& wallet){
    cout << endl << endl << setfill('*') << setw(30) << "" << endl;
    cout << setfill(' ') << setw(5) << "" << "Welcome to EZ-Mart!" << endl;
    cout << setfill(' ') << setw(5) << "" << "Your One Stop" << endl;
    cout << setfill(' ') << setw(5) << "" << "E-Commerce Shop!" << endl;
    cout << setfill('*') << setw(30) << "" << endl;
    cout << endl << "What is your name? " << endl; 
    cin >> name;
    cout << "How much would you like to deposit to your wallet? " << endl;
        // Error check loop to make sure user enter's Numerical input
        while (!(cin >> wallet)) {
        cin.clear();
        cout << "Invalid input. Please enter a valid number." << endl;
        cout << "How much would you like to deposit to your wallet? $";
        cin.ignore(); // ignore the invalid input
    }
    cout << " *** Welcome " << name << " *** " << endl;
}
    // This is the Main Menu
void mainMenu(int& choice) {
    cout << endl << setfill('-') << setw(30) << "" << endl; 
    cout <<setw(5) << setfill(' ') << "" << "--- Main Menu ---" << endl;
    cout << setfill('-') << setw(30) << "" << endl; 
    cout << "1 - View Inventory" << endl;
    cout << "2 - Account Balance" << endl;
    cout << "3 - View Cart" << endl;
    cout << "4 - Checkout" << endl;
    cout << "0 - Exit Application" << endl << endl;
    choiceMaker(choice); 
}
    // Reusable function that requires user input and returns the choice
int choiceMaker(int& choice){
    cout << setfill('*') << setw(30) << "" << endl;
    cout << "" << "Enter The Number For your Choice: ";
    cin >> choice;
    cout << setfill('*') << setw(30) << "" << endl;
    return choice;
}
    // Inventory menu
void viewInventory(int itemNum, double& total, double taxAmt, double taxRate){
    int invChoice = -1;
            cout << setfill('-') << setw(30) << "" << endl;
            cout << setfill (' ') << setw(10) << "" << "Inventory:" << endl;
            cout << setfill('-') << setw(30) << "" << endl;
    while (invChoice !=0) 
    {
        // For loop to print out Number selection and item name
        for (int i = 0; i < inventory.size(); i++) {
            cout << setfill('-') << setw(30) << "" << endl;
            cout << setfill(' ') << setw(10) << "" << "*** Item # " << (i + 1) << " ***" << endl;
            cout << left << "Item Name: " << setw(3) << "\n" << right << inventory[i].name << endl;
            cout << left << "Item Price: " << setw(3) << "\n" << right << "$" <<  inventory[i].price << endl;
            cout << left << "Item URL: " << setw(3) << "\n" << right << inventory[i].url << endl;
            cout << setfill('-') << setw(30) << "" << endl;
        }
        cout << endl << "1 - Add items to cart" << endl;
        cout << "0 - Back to Previous Menu" << endl;
        choiceMaker(invChoice);

        switch (invChoice)
        {
        case 1:
            addToCart(itemNum, total, taxAmt, taxRate);
            break;
        case 0:
            break;
        default:
            "invalid choice please try again";
            break;
        }
    }
}
    // Wallet Info
void viewAccount(string name, double wallet, int choice) {
    cout << endl << setfill('-') << setw(30) << "" << endl;
    cout << endl << setfill(' ')<< setw(5) << "" << "--- Hello " << name << " --- " << endl;
    cout << "Your Account Balance is: $" << wallet << endl;
    cout << endl << setfill('-') << setw(30) << "" << endl;
    cout << endl << " 0 - Previous Menu" << endl;
    choiceMaker(choice);
    if (choice != 0) {
        cout << "Invalid Selection Please Try Again" << endl;
        choiceMaker(choice);
    } else{
        return;
    }
}
    // Function that adds the user's Choice of items to the cart Vector
void addToCart(int itemNum, double& total, double& taxAmt, double taxRate){
        cout << setfill('-') << setw(30) << "" << endl;
        cout << "Enter The Item # to add to cart" << endl;
        cout << setfill('-') << setw(30) << "" << endl;
        cin >> itemNum;
        // For loop to add each selected item into the cart vector
        for (int i = 0; i < inventory.size(); i++){
            if (itemNum == i+1 ) {
                cart.push_back({inventory[i].name, inventory[i].price, inventory[i].url, inventory[i].category});
                total += inventory[i].price;
                taxAmt += total * taxRate; 
            }
        }
}
    // Function that displays the items in the user's cart from the cart vector
void viewCart(double& total, double taxAmt, double taxRate, int choice){
    cout << setfill('-') << setw(30) << "" << endl;
    cout << setfill(' ') << setw(5) << "" << "Items In Your Cart" << endl;
    cout << setfill('-') << setw(30) << "" << endl;
    // for loop returning all the items in the cart vector
    for (int i = 0; i < cart.size(); i++) {
        cout << "Item: " << cart[i].name << endl;
        cout << "Price:" << cart[i].price << endl << endl;
    }
    // conditional statement showing either cart is empty, or cart has items
    if (cart.size() < 1) {
        cout << setfill('-') << setw(30) << "" << endl;
        cout << setfill(' ') << setw(5) << "--- Your Cart Is Empty ---" << endl;
        cout << setfill('-') << setw(30) << "" << endl;
    } else if (cart.size() > 0 ) {
        taxAmt = total * taxRate;
    cout << "Taxes: $" << taxAmt << endl;
    cout << "Price: $" << total << endl;
    cout << "Total Price: $" << total + taxAmt << endl; 
    }
    cout << endl << "0 - Return To Previous Menu" << endl;
    choiceMaker(choice);

    if (choice != 0) {
        
        while (choice != 0)
        {
            cout << "Invalid Selection Please Try Again" << endl;
            choiceMaker(choice);
        }
        
    } else {
        return;
    }
}
    // Function that carries out the checkout process, ie. subtract from wallet balance and remove items from the cart
void itemCheckOut(double& wallet, double& total, int choice, double& taxAmt, double taxRate){
    taxAmt = total * taxRate;
    cout << setfill('-') << setw(30) << "" << endl;
    cout << setfill(' ') << setw(5) << "" << "--- Checkout ---" << endl;
    cout << setfill('-') << setw(30) << "" << endl;

    cout << "your wallet balance: $" << wallet << endl;
    cout << "Will be deducted by $" << total << " + $" << setprecision(2) << fixed << taxAmt << " in taxes" << endl;
    cout << "Your Total payment will be: $" << total + taxAmt <<endl;
    cout << "Do you want to continue? 1-yes 2-no" << endl;
    choiceMaker(choice);
    if (choice == 1) {
        cart.clear();
        if (wallet < (total + taxAmt)) {
            cout << "You Have Insufficient Funds." << endl;
        } else {
        wallet = wallet - (total + taxAmt);
        total = 0;
        taxAmt = 0;
        cout << "Your new wallet balance is: $" << wallet << endl;
        }
    } else {
        return;
    }
}

