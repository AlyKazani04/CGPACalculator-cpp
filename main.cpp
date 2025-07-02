//CGPA calculator
// This program calculates the CGPA based on user input for grades and credits.


#include <bits/stdc++.h>
#include <limits>
#include <conio.h>
#include "calculator.hpp"
using namespace std;

inline void clearScreen();

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

                break; 
            case 2:
                clearScreen();

                calc.calculateCGPA();

                cout << "==========================================" << endl;
                cout << '\n' << "Press any key to continue..." << endl;
                if(_kbhit()) 
                {
                    _getch();
                }
                break; 
            case 3:
                clearScreen();

                calc.displayLogo();

                calc.displaySGPAs();
                calc.displayCGPA();

                cout << "==========================================" << endl;
                cout << '\n' << "Press any key to continue..." << endl;
                if(_kbhit()) 
                {
                    _getch();
                }
                break; 
            case 4:
                
                cout << "==========================================" << endl;
                cout << '\n' << "Press any key to continue..." << endl;
                if(_kbhit()) 
                {
                    _getch();
                }
                break;
            case 0:
                if(calc.exitProgram()) { return 0; }
                break; 
            default:
                cout << "Invalid choice, please try again." << endl;
                cout << "==========================================" << endl;
                cout << '\n' << "Press any key to continue..." << endl;
                if(_kbhit()) 
                {
                    _getch(); // wait for user to press Enter
                }
                break;
        }
    }

    return 0;
}

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}