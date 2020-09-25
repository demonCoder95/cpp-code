// Class implementation of the Employee class.
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;


// class constructor
Employee::Employee(string givenFirstName, string givenLastName, int givenSalary){
    setFirstName(givenFirstName);
    setLastName(givenLastName);
    setSalary(givenSalary);
}

// get function for firstName
string Employee::getFirstName(){
    return firstName;
}

// set function for firstName
void Employee::setFirstName(string givenFirstName){
    firstName = givenFirstName;
}

// get function for lastName
string Employee::getLastName(){
    return lastName;
}

// set function for lastName
void Employee::setLastName(string givenLastName){
    lastName = givenLastName;
}

// get function for salary
int Employee::getSalary(){
    return salary;
}

// set function for salary
void Employee::setSalary(int givenSalary){
    if (givenSalary <= 0){
        cerr << "Invalid salary. Setting to 0." << endl;
        salary = 0;
    }else {
        salary = givenSalary;
    }
}