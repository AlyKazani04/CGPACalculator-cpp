#pragma once

#include <bits/stdc++.h>
using namespace std;

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
        vector<float> m_grades;
        vector<int> m_credithrs;
        vector<float> m_sgpas;
        vector<int> m_semHrs;

        // private methods
        void clearScreen();
    public:
        Calculator() = default;

        void calculateSGPA();
        void calculateCGPA();

        void displayLogo();
        void displayMenu();
        void addGrade(float grade, int hrs);
        
        void setNumCourses(int courses);
};