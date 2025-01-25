// Programming 3
// Utility.h
// COSC - 2436-002
// Nigel Poblete
// Dr Kevin Roark
// Date:
//* Description:
   // A Header File
#ifndef UtilityFile_hpp
#define UtilityFile_hpp
#include <string>
using namespace std;

void menuHeader(string&,double&);
void mainMenu(int&);
int choiceMaker(int&);
void viewInventory(int, double&, double, double);
void viewAccount(string, double, int);
void addToCart(int, double&, double&, double);
void viewCart(double&, double, double, int);
void itemCheckOut(double&, double&, int, double&, double);


#endif // end of Utility file