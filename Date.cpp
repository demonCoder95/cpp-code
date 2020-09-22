// Implementation of the Date class.
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

// class constructor implementation
Date::Date(int givenMonth, int givenDay, int givenYear){
    setMonth(givenMonth);
    setDay(givenDay);
    setYear(givenYear);
}

// get function for month
int Date::getMonth(){
    return month;
}

// set function for month
void Date::setMonth(int givenMonth){
    if (givenMonth <= 12 && givenMonth >= 1){
        month = givenMonth;
    }else{
        cerr << "Invalid month. Setting to 1." << endl;
        month = 1;
    }
}

// get function for day
int Date::getDay(){
    return day;
}

// set function for day
void  Date::setDay(int givenDay){
    day = givenDay;
}

// get function for year
int Date::getYear(){
    return year;
}

// set function for year
void Date::setYear(int givenYear){
    year = givenYear;
}

// function to display date in month/day/year format
void Date::displayDate(){
    cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}