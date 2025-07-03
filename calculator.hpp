#pragma once

#include <bits/stdc++.h>
#include <limits>
using namespace std;

// method to clear console screen
inline void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

class Calculator{
    private:
        // constants
        const int m_maxSems = 8;
        const int m_maxCourses = 10;
        const int m_maxCredithrs = 4;
        const int m_maxGrade = 4;

        // variables
        int m_userSems = 0;
        int m_numCourses = 0;
        int m_totalCreditHrs = 0;

        // for a single semester
        vector<float> m_grades;
        vector<int> m_credithrs;

        // for all semesters
        vector<float> m_sgpas;
        vector<int> m_semHrs;

        // private methods
        void addGrade(float grade, int hrs);
    public:
        Calculator() = default;
        
        void displayLogo();
        void displayMenu();
        bool exitProgram();
        
        float calculateSGPA();
        float calculateCGPA();
        
        void displaySGPAs();
        void displayCGPA();

        void enterDetails();

        ~Calculator() = default;
};