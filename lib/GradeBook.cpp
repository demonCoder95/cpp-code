// Implementation of member function of the GradeBook class
#include <iostream>
#include <iomanip>  // parametrized io manipulator
#include "GradeBook.h"
using namespace std;

// constructor of the class
GradeBook::GradeBook(string nameOfCourse, string nameOfInstructor, const int gradesArray[][tests]){
    setCourseName(nameOfCourse);
    setInstructorName(nameOfInstructor);
    
    // // Initialize grade counts to 0
    // aCount = 0;
    // bCount = 0;
    // cCount = 0;
    // dCount = 0;
    // fCount = 0;

    // initialize maximum grade to 0
    maximumGrade = 0;

    for (int grade = 0; grade < students; grade++){
        for (int test = 0; test < tests; test++){
            grades[grade][test] = gradesArray[grade][test];
        }
    }
}

// function to set courseName
void GradeBook::setCourseName(string name){
    if (name.length() < 25){
        courseName = name;
    } else {
        courseName = name.substr(0, 25);
        cerr << "Name " << name << " exceeds maximum length (25).\n" 
             << "Limiting length to 25 characters." << endl;
    }
}

// function to get courseName
string GradeBook::getCourseName(){
    return courseName;
}

// function to display welcome message to the user
void GradeBook::displayMessage(){
    cout << "Welcome to the grade book for " << getCourseName() << "!" << endl;
    cout << "This course is presented by: " << getInstructorName() << endl;
}

// function to set the instructorName
void GradeBook::setInstructorName(string name){
    instructorName = name;
}

// function to get the instructorName
string GradeBook::getInstructorName(){
    return instructorName;
}

// determine class average of 10 grades entered by the user
void GradeBook::determineClassAverage(){
    int total; // sum of grades entered by user
    int gradeCounter; // number of grades entered by user
    int grade; // grade value entered by user
    double average; // average of grades

    // initialize variables
    total = 0;
    gradeCounter = 0;

    cout << "Enter grade or -1 to quit: ";
    cin >> grade;

    while (grade != -1){

        total += grade;
        gradeCounter++;

        cout << "Enter grade or -1 to quit: ";
        cin >> grade;
    }

    if (gradeCounter != 0){

        average = static_cast<double>(total) / gradeCounter; // integer division for now

        cout << "\nTotal of all " << gradeCounter << " grades is " << total << endl;
        cout << "Class average is " << setprecision(2) << fixed << average << endl;
    }else {
        cout << "No grades were entered" << endl;
    }
}

// // Input arbitrary number of grades from the user: upgrade grade counters
// void GradeBook::inputGrades(){
//     int grade;  // grade entered by the user

//     cout << "Enter the letter grades." << endl 
//         << "Enter the EOF character to end input." << endl;
    
//     while ((grade = cin.get()) != EOF ){
//         switch (grade){
//             case 'A':
//             case 'a':
//                 ++aCount;
//                 break;
//             case 'B':
//             case 'b':
//                 ++bCount;
//                 break;
//             case 'C':
//             case 'c':
//                 ++cCount;
//                 break;
//             case 'D':
//             case 'd':
//                 ++dCount;
//                 break;
//             case 'F':
//             case 'f':
//                 ++fCount;
//                 break;
//             case '\n':
//             case '\t':
//             case ' ':
//                 break;  // ignore whitespaces
//             default:
//                 cout << "Incorrect letter grade entered."
//                     << " Enter a new grade. " << endl;
//                 break;
//         }
//     }
// }

// void GradeBook::displayGradeReport(){
//     cout << "\n\nNumber of students who received each letter grade:"
//         << "\nA: " << aCount
//         << "\nB: " << bCount
//         << "\nC: " << cCount
//         << "\nD: " << dCount
//         << "\nF: " << fCount
//         << endl;
// }

void GradeBook::inputGrades(){
    // grades entered by the user
    int grade1, grade2, grade3;
    cout << "Enter three integer grades: ";
    cin >> grade1 >> grade2 >> grade3;

    maximumGrade = maximum(grade1, grade2, grade3);
}

void GradeBook::displayGradeReport(){
    cout << "Maximum of grades entered: " << maximumGrade << endl;
}

int GradeBook::maximum(int x, int y, int z){
    int maximumvalue = x;

    if (y > maximumvalue){
        maximumvalue = y;
    }

    if (z > maximumvalue){
        maximumvalue = z;
    }

    return maximumvalue;
}

void GradeBook::processGrades(){
    outputGrades();

    cout << "\nLowest grade is " << getMinimum() << 
        "\nHighest grade is " << getMaximum() << endl;

    outputBarChart();
}

int GradeBook::getMinimum(){
    int lowGrade = 100;

    for (int grade = 0; grade < students; ++grade){
        for (int test = 0; test < tests; test++){
            if (grades[grade][test] < lowGrade){
                lowGrade = grades[grade][test];
            }
        }
    }

    return lowGrade;
}

int GradeBook::getMaximum(){
    int highGrade = 0;

    for (int grade = 0; grade < students; ++grade){
        for (int test = 0; test < tests; test++){
            if (grades[grade][test] > highGrade){
                highGrade = grades[grade][test];
            }
        }
    }

    return highGrade;
}

double GradeBook::getAverage(const int setOfGrades[], const int grades){
    int total = 0;

    for (int grade = 0; grade < grades; ++grade){
        total += setOfGrades[grade];
    }

    return static_cast<double>(total) / grades;
}

void GradeBook::outputBarChart(){
    cout << "\nGrade distribution: " << endl;

    // store frequency of grades in ranges of 10
    const int frequencySize = 11;
    int frequency[frequencySize] = {};      // initialize to 0

    for (int student =0; student < students; ++student){
        for (int test = 0; test < tests; test++){
            ++frequency[grades[student][test]/10];
        }
    }

    for (int count = 0; count < frequencySize; ++count){
        if (count == 0)
        cout << "  0-9: ";
        else if (count == 10)
        cout << "  100: ";
        else 
        cout << count * 10 << "-" << (count * 10) + 9 << ": ";

        for (int stars = 0; stars < frequency[count]; ++stars){
            cout << "*";
        }

        cout << endl;
    }
}

void GradeBook::outputGrades(){
    cout << "\nThe grades are:\n\n";
    cout << "            ";

    for (int test = 0; test < tests; test++){
        cout << "Test " << test + 1 << "  ";
    }

    cout << "Average" << endl;


    for (int student = 0; student < students; student++){
        cout << "Student " << setw(2) << student + 1;
        
        for ( int test = 0; test < tests; ++test){
            cout << setw(8) << grades[student][test];
        }

        double average = getAverage(grades[student], tests);
        cout << setw(9) << setprecision(2) << fixed << average << endl;
    }
}