// Implementation of member function of the GradeBook class
#include <iostream>
#include "GradeBook.h"
using namespace std;

// constructor of the class
GradeBook::GradeBook(string nameOfCourse, string nameOfInstructor){
    setCourseName(nameOfCourse);
    setInstructorName(nameOfInstructor);
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