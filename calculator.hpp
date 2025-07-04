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
        const int m_maxSems = 8;        // 4 years with 2 semesters each
        const int m_maxCourses = 10;    // max courses per semester
        const int m_maxCredithrs = 4;   // max credit hours per course
        const int m_maxGrade = 4;       // max grade (4.0 scale)    

        // variables
        int m_userSems = 0;             // number of semesters user wants to enter
        int m_numCourses = 0;           // number of courses in a semester
        int m_totalCreditHrs = 0;       // total credit hours for all semesters

        // for a single semester
        vector<float> m_grades;         // grades for each course in the semester
        vector<int> m_credithrs;        // credit hours for each course in the semester

        // for all semesters
        vector<float> m_sgpas;          // semester GPAs
        vector<int> m_semHrs;           // semester credit hours

        // private methods

        /// @brief Adds a grade and its credit hours to the current semester.
        /// @param grade the grade (0.0 - 4.0)
        /// @param hrs credit hours for the course (1 - 4)  
        void addGrade(float grade, int hrs);
    public:
        Calculator() = default;
        
        /// @brief display logo of the calculator
        void displayLogo();

        /// @brief display main menu  
        void displayMenu();

        /// @brief asks confirmation to exit the program
        /// @return true if user wants to exit, false otherwise
        bool exitProgram();
        
        /// @brief calculates SGPA for the current semester. (grade * credit hours) / total credit hrs for the semester
        /// @return returns the SGPA for the current semester
        /// @note returns 0.0 if no courses are entered
        float calculateSGPA();

        /// @brief calculates CGPA for all semesters. (sum of (SGPA * credit hrs) / total credit hrs for all semesters)
        /// @return returns CGPA for all semesters
        /// @note returns 0.0 if no semester is found
        float calculateCGPA();
        
        /// @brief displays SGPAs for all semesters
        void displaySGPAs();

        /// @brief displays the CGPA
        void displayCGPA();

        /// @brief prompts user to enter details for all semesters
        /// @note clears all previous data before entering new details
        void enterDetails();

        ~Calculator() = default;
};