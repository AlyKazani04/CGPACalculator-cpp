#include "calculator.hpp"
using namespace std;

// display functions

void Calculator::displayLogo()
{
    cout << "==========================================" << endl;
    cout << "             CGPA Calculator              " << endl;
    cout << "                  By Aly                  " << endl;
    cout << "==========================================" << endl;
}

void Calculator::displayMenu()
{
    displayLogo();
    cout << "\n";
    cout << "1. Enter CGPA Details" << endl;
    cout << "2. Calculate CGPA" << endl;
    cout << "3. Display Result" << endl;
    cout << "0. Exit" << endl;
}

void Calculator::displaySGPAs()
{
    if(m_sgpas.empty())
    {
        cout << "No SGPAs available. Please enter all details first." << endl;
        return;
    }

    cout << "             Semester SGPAs              " << endl;
    cout << endl;

    for(int i = 0; i < m_sgpas.size(); i+=2)
    {
        cout << fixed << setprecision(2) << "Semester " << i + 1 << ": " << m_sgpas[i] << "\tSemester " << i + 2 << ": " << m_sgpas[i+1] << endl;
    }
    cout << "==========================================" << endl;

    cout << "Total Credit Hours: " << m_totalCreditHrs << endl;
    cout << "Total Semesters: " << m_sgpas.size() << endl;
}

void Calculator::displayCGPA()
{
    if(m_sgpas.empty())
    {
        cout << "No SGPAs available. Please enter all details first." << endl;
        return;
    }

    float CGPA = calculateCGPA();

    cout << "==========================================" << endl;
    cout << "                  CGPA                   " << endl;
    cout << "==========================================" << endl;
    cout << fixed << setprecision(2) << "CGPA: " << CGPA << endl;
}

bool Calculator::exitProgram()
{
    char choice;

    do{
        cout << "Are you sure you want to exit? (y/n): ";
        cin >> choice;

        choice = tolower(choice);

        if(choice != 'y' && choice != 'n')
        {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
        }

    }while(choice != 'y' && choice != 'n');

    if(choice == 'y')
    {
        cout << "Exiting... " << endl;
        return true;
    }
    else
    {
        cout << "Returning to menu..." << endl;
        return false;
    }

}

// logic functions

float Calculator::calculateSGPA()
{
    float SGPA;
    int totalGradePoints = 0;
    int totalSemHrs = 0;
    
    for(int i = 0; i < m_numCourses; i++)
    {
        totalGradePoints += m_grades[i] * m_credithrs[i];
    }
    
    for(auto& hrs : m_credithrs)
    {
        totalSemHrs += hrs;
    }
    
    m_semHrs.push_back(totalSemHrs);
    
    if(totalSemHrs > 0)
    {
        SGPA = totalGradePoints / (float)totalSemHrs;
        m_sgpas.push_back(SGPA);
        cout << "SGPA for this semester: " << SGPA << endl;
        return SGPA;
    }
    
    cout << "No credit hours available." << endl;
    
    m_sgpas.push_back(0);
    cout << "SGPA for this semester: 0.0"<< endl;

    return 0;
}

float Calculator::calculateCGPA()
{
    float CGPA = 0;
    float totalSGPAs = 0;
    
    for(auto& sgpa : m_sgpas)
    {
        totalSGPAs += sgpa;
    }
    
    if(!m_sgpas.empty())
    {
        CGPA = totalSGPAs / m_userSems;
        // cout << "CGPA: " << CGPA << endl;
        return CGPA;
    }
    
    cout << "No SGPAs available." << endl;
    return 0;
}

// input functions

void Calculator::enterDetails()
{
    int numCourses;
    bool fail = true;
    int sems = 0;

    m_totalCreditHrs = 0;
    m_sgpas.clear();
    m_semHrs.clear();
    m_grades.clear();
    m_credithrs.clear();
    m_userSems = 0;
    m_numCourses = 0;

    displayLogo();

    do{
        cout << "Enter number of semesters completed(1 to " << m_maxSems << "): \n> ";
        cin >> sems;

        if(cin.fail() || sems < 1 || sems > m_maxSems)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number of semesters. Please enter number semesters between 1 and " << m_maxSems << "." << endl;
            fail = true;
        }
        else
        {
            m_userSems = sems;
            fail = false;
        }
        cin.clear();

    }while(fail);

    cout << "You will now enter the details for " << m_userSems << " semesters." << endl;
    for(int i = 0; i < m_userSems; i++)
    {
        clearScreen();
        
        cout << "==========================================" << endl;
        cout << "          Enter Semester " << i + 1 << " Details" << endl;
        cout << "==========================================" << endl;

        do{
            cout << "Enter the number of courses for semester " << i + 1 << "(max "<< m_maxCourses << " courses): ";
            cin >> numCourses;
            
            if(cin.fail() || numCourses < 1 || numCourses > m_maxCourses)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number of courses. Please enter a value between 1 and  " << m_maxCourses << "." << endl;
                fail = true;
            }
            else
            {
                m_numCourses = numCourses;
                fail = false;
            }
        }while(fail);

        m_grades.clear();
        m_credithrs.clear();

        for(int j = 0; j < m_numCourses; j++)
        {
            float grade;
            int hrs;
            
            cout << "Enter grade for course " << j + 1 << " (0.0 to " << m_maxGrade << "): ";
            cin >> grade;
            
            if(cin.fail() || grade < 0.0 || grade > m_maxGrade)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid grade. Please enter a value between 0.0 and " << m_maxGrade << "." << endl;
                j--; // repeat this cycle for this course
                continue;
            }
            
            cout << "Enter credit hours for course " << j + 1 << " ( 1 to " << m_maxCredithrs << "): ";
            cin >> hrs;
            
            if(cin.fail() || hrs < 1 || hrs > m_maxCredithrs)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid credit hours. Please enter a value between 1 and " << m_maxCredithrs << "." << endl;
                j--; // repeat this cycle for this course
                continue;
            }
            
            addGrade(grade, hrs);

            m_totalCreditHrs += hrs;
            cout << "Grade and credit hours for course " << j + 1 << " added successfully." << endl;
        }
        
        if(calculateSGPA() > 0.f)
        {
            cout << "Entered semester " << i + 1 << " details successfully." << endl;
        }        
    }
}

// Setters
void Calculator::addGrade(float grade, int hrs)
{
    m_grades.push_back(grade);
    m_credithrs.push_back(hrs);
}
