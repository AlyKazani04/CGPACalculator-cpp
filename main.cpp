//CGPA calculator
// This program calculates the CGPA based on user input for grades and credits.


#include <bits/stdc++.h>
#include <limits>
#include <conio.h>
#include "calculator.hpp"
using namespace std;

int main(){
    
    Calculator calc;
    int choice;
    
    while(1){
        clearScreen();
        calc.displayMenu();

        cout << "> ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            choice = -1; // reset choice to invalid value
            cin.ignore(); // clear input buffer
        }

        switch(choice){
            case 1:
                clearScreen();

                calc.enterDetails();

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break; 
            case 2:
                clearScreen();

                calc.displayCGPA();

                cout << '\n' << "Press any key to continue..." << endl;

                _getch();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                break; 
            case 3:
                clearScreen();

                calc.displayLogo();

                calc.displaySGPAs();
                calc.displayCGPA();

                cout << '\n' << "Press any key to continue..." << endl;

                _getch();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                break;
            case 0:
                if(calc.exitProgram()) { return 0; }

                break; 
            default:

                cout << "Invalid choice, please try again." << endl;
                cout << "==========================================" << endl;
                cout << '\n' << "Press any key to continue..." << endl;

                _getch();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                break;
        }
    }

    return 0;
}