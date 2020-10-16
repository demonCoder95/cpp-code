#include <iostream>
#include "GradeBook.h"
#include "Account.h"
#include "Invoice.h"
#include "Employee.h"
#include "Date.h"
#include "HeartRates.h"
#include "HealthProfile.h"

using namespace std;

int main(){

    //int gradesArray[GradeBook::students] = {87, 68, 94, 100, 83, 78, 85, 91, 76, 87};

    int gradesArray [GradeBook::students][GradeBook::tests] = 
    {
        {87, 96, 70},
        {68, 87, 90},
        {94, 100, 90},
        {100, 81, 82},
        {83, 65, 85},
        {78, 87, 65},
        {85, 75, 83},
        {91, 94, 100},
        {76, 72, 84},
        {87, 93, 73}
    };

    GradeBook myGradeBook("Linux Programming", "Noor Muhammad", gradesArray);
    myGradeBook.displayMessage();

    myGradeBook.processGrades();
    // myGradeBook.inputGrades();
    // myGradeBook.displayGradeReport();

    // Account myAccount(100);
    // cout << "My account balance is: " << myAccount.getBalance() << endl;

    // Invoice myInvoice("A0123BK90", "Absolute Zero Centrifuge", 10, 199);
    // cout << "Invoice amount is: $" << myInvoice.getInvoiceAmount() << endl;

    // Employee myEmployee("John", "Doe", 1000);
    // cout << "Yearly salary of " << myEmployee.getFirstName() << " " << myEmployee.getLastName()
    //      << " is $" << myEmployee.getSalary()*12 << endl;
    
    // Date myDate(9, 22, 2020);
    // cout << "Today is "; myDate.displayDate(); cout << endl;

    // Date myDateOfBirth(8, 15, 1990);
    // HeartRates myHeartRates("John", "McClane", myDateOfBirth);

    // TargetHeartRateRange myTargetHeartRateRange = myHeartRates.getTargetHeartRate();
    // cout << "Target rate: " << myTargetHeartRateRange.minTargetHeartRate << "-" 
    //      << myTargetHeartRateRange.maxTargetHeartRate << " BPM" << endl;

    // Date myDateOfBirth(9, 11, 2001);
    // HealthProfile myHealthProfile("Ethan", "Hunt", 'M', myDateOfBirth, 70, 200);

    // // Printing the HealthProfile information
    // cout << "HEALTH PROFILE RECORD" << endl;
    // cout << "Name: " << myHealthProfile.getLastName() << ", " << myHealthProfile.getFirstName() << endl;
    // cout << "Gender: " << myHealthProfile.getGender() << endl;
    // cout << "DOB: ";
    // myHealthProfile.getDateOfBirth().displayDate();
    // cout << "Height: " << myHealthProfile.getHeight() << " inches" << endl;
    // cout << "Weight: " << myHealthProfile.getWeight() << " pounds" << endl;
    // cout << "Age: " << myHealthProfile.heartRates.getAge() << " years" << endl;
    // cout << "Max Heart Rate: " << myHealthProfile.heartRates.getMaximumHeartRate() << " Beats per Minute" << endl;
    // cout << "Target Heart Rate Range: " <<myHealthProfile.heartRates.getTargetHeartRate().minTargetHeartRate << "-"
    //      << myHealthProfile.heartRates.getTargetHeartRate().maxTargetHeartRate << " Beats per Minute" << endl;


    return 0;
}