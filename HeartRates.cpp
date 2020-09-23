// Implementation of the class HeartRates
#include<string>
#include<iostream>
#include "HeartRates.h"
#include "Date.h"
using namespace std;

HeartRates::HeartRates(string givenFirstName, string givenLastName, Date givenDateOfBirth){
    setFirstName(givenFirstName);
    setLastName(givenLastName);
    dateOfBirth = givenDateOfBirth;
}

// get function for firstName
string HeartRates::getFirstName(){
    return firstName;
}

// set function for firstName
void HeartRates::setFirstName(string givenFirstName){
    firstName = givenFirstName;
}

// get function for lastName
string HeartRates::getLastName(){
    return lastName;
}

// set function for lastName
void HeartRates::setLastName(string givenLastName){
    lastName = givenLastName;
}

// get function for dateOfBirth
Date HeartRates::getDateOfBirth(){
    return dateOfBirth;
}

// set function for dateOfBirth
void HeartRates::setDateOfBirth(Date givenDateOfBirth){
    dateOfBirth = givenDateOfBirth;
}

/* function to return age in years - NOT HANDLING LEAP YEARS -
DAYS/MONTH APPROXIMATED TO 30 DAYS*/
int HeartRates::getAge(){
    int currentDay, currentMonth, currentYear;
    cout << "Enter current day: " << endl;
    cin >> currentDay;
    cout << "Enter current month: " << endl;
    cin >> currentMonth;
    cout << "Enter current year: " << endl;
    cin >> currentYear;

    /* If number of days passed in currentYear is >= number of days
    passed in the birthYear, birthday has passed/is today. Otherwise, 
    age will be 1 year less than the difference of years.*/
    
    //TODO: Implement leap year check and month->day mapping

    // compute days in birth year
    Date dateOfBirth = getDateOfBirth();
    int birthYearDays = dateOfBirth.getMonth() * 30 + dateOfBirth.getDay();

    // compute days in current year
    int currentYearDays = currentMonth*30 + currentDay;

    // if birthday hasn't passed yet
    if (currentYearDays < birthYearDays){
        // age is 1 year less
        return currentYear - dateOfBirth.getYear() -1;
    }else {
        // otherwise, age is simply the difference of years
        return currentYear - dateOfBirth.getYear();
    }
}

// function to get maximum heart rate in Beats per Minute
int HeartRates::getMaximumHeartRate(){
    return 220 - getAge();
}

// function to get target heart rate in Beats per Minute
TargetHeartRateRange HeartRates::getTargetHeartRate(){
    TargetHeartRateRange calculatedRange;
    int maximumHeartRate = getMaximumHeartRate();

    //TODO: FIX THIS TO ADD FLOATING POINTS IN THE STRUCT

    // minimum target range is 50% of maximum
    calculatedRange.minTargetHeartRate = 0.5*maximumHeartRate;

    // maximum target rate is 85% of maximum
    calculatedRange.maxTargetHeartRate = 0.85*maximumHeartRate;

    return calculatedRange;
}