// Class implementation for HealthProfile class
#include <string>
#include "Date.h"
#include "HeartRates.h"
#include "HealthProfile.h"
using namespace std;

HealthProfile::HealthProfile(string givenFirstName, string givenLastname, 
    char givenGender, Date givenDateOfBirth, int givenHeight, int givenWeight){
        // TODO: Figure out why default constructor for HeartRates is needed for this

    setFirstName(givenFirstName);
    setLastName(givenLastname);
    setGender(givenGender);
    setDateOfBirth(givenDateOfBirth);
    setHeight(givenHeight);
    setWeight(givenWeight);

    // No need to initialize names, they will never be used here
    heartRates.setDateOfBirth(givenDateOfBirth);
    }

// get function for firstName
string HealthProfile::getFirstName(){
    return firstName;
}

// set function for firstName
void HealthProfile::setFirstName(string givenFirstName){
    firstName = givenFirstName;
}

// get function for lastName
string HealthProfile::getLastName(){
    return lastName;
}

// set function for lastName
void HealthProfile::setLastName(string givenLastName){
    lastName = givenLastName;
}

// get function for gender
char HealthProfile::getGender(){
    return gender;
}

// set function for gender
void HealthProfile::setGender(char givenGender){
    gender = givenGender;
}

// get function for dateOfBirth
Date HealthProfile::getDateOfBirth(){
    return dateOfBirth;
}

// set function for dateOfBirth
void HealthProfile::setDateOfBirth(Date givenDateOfBirth){
    dateOfBirth = givenDateOfBirth;
}

// get function for height
int HealthProfile::getHeight(){
    return height;
}

// set function for height
void HealthProfile::setHeight(int givenHeight){
    height = givenHeight;
}

// get function for weight
int HealthProfile::getWeight(){
    return weight;
}

// set function for weight
void HealthProfile::setWeight(int givenWeight){
    weight = givenWeight;
}

