// Implementation of member function of the GradeBook class
#include <iostream>
#include <iomanip>  // parametrized io manipulator
#include "GradeBook.h"
using namespace std;

// constructor of the class
GradeBook::GradeBook(string nameOfCourse, string nameOfInstructor){
    setCourseName(nameOfCourse);
    setInstructorName(nameOfInstructor);
    
    // Initialize grade counts to 0
    aCount = 0;
    bCount = 0;
    cCount = 0;
    dCount = 0;
    fCount = 0;
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

// Input arbitrary number of grades from the user: upgrade grade counters
void GradeBook::inputGrades(){
    int grade;  // grade entered by the user

    cout << "Enter the letter grades." << endl 
        << "Enter the EOF character to end input." << endl;
    
    while ((grade = cin.get()) != EOF ){
        switch (grade){
            case 'A':
            case 'a':
                ++aCount;
                break;
            case 'B':
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'F':
            case 'f':
                ++fCount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;  // ignore whitespaces
            default:
                cout << "Incorrect letter grade entered."
                    << " Enter a new grade. " << endl;
                break;
        }
    }
}

void GradeBook::displayGradeReport(){
    cout << "\n\nNumber of students who received each letter grade:"
        << "\nA: " << aCount
        << "\nB: " << bCount
        << "\nC: " << cCount
        << "\nD: " << dCount
        << "\nF: " << fCount
        << endl;
}