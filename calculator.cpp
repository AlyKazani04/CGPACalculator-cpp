#include "calculator.hpp"
using namespace std;

void Calculator::clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Calculator::displayLogo()
{
    cout << "==========================================" << endl;
    cout << "             CGPA Calculator              " << endl;
    cout << "                  By Aly                  " << endl;
    cout << "==========================================" << endl;
}

void Calculator::displayMenu()
{
    clearScreen();
    displayLogo();
    cout << "\n";
    cout << "1. Enter SGPAs" << endl;
    cout << "2. Check All SGPAs" << endl;
    cout << "3. Calculate CGPA" << endl;
    cout << "0. Exit" << endl;
}

void Calculator::addGrade(float grade, int hrs)
{
    m_grades.push_back(grade);
    m_credithrs.push_back(hrs);
}

void Calculator::calculateSGPA()
{
    float SGPA;
    int totalSemCourses = 0;
    int totalSemHrs = 0;

    for(int i = 0; i < m_numCourses; i++)
    {
        totalSemCourses += m_grades[i] * m_credithrs[i];
    }

    for(auto& hrs : m_credithrs)
    {
        totalSemHrs += hrs;
    }

    m_semHrs.push_back(totalSemHrs);

    if(totalSemHrs > 0)
    {
        SGPA = totalSemCourses / (float)totalSemHrs;
        m_sgpas.push_back(SGPA);
        cout << "SGPA for this semester: " << SGPA << endl;
    }
}

// Setters

void Calculator::setNumCourses(int courses)
{
    m_numCourses = courses;
}