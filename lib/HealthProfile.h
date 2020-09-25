// HealthProfile class public specification. This hides the implementation details
#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H
#include <string>
#include "Date.h"
#include "HeartRates.h"

using namespace std;

class HealthProfile{
    public:
        HeartRates heartRates;
        
        HealthProfile(string, string, char, Date, int, int);    // constructor for the class

        string getFirstName();  // get function for firstName
        void setFirstName(string); // set function for firstName

        string getLastName(); // get function for lastName
        void setLastName(string); // set function for lasName

        char getGender(); // get function for gender
        void setGender(char); // set function for gender

        Date getDateOfBirth(); // get function for dateOfBirth
        void setDateOfBirth(Date); // set function for dateOfBirth

        int getHeight(); // get function for height
        void setHeight(int); // set function for height

        int getWeight(); // get function for weight
        void setWeight(int); // set function for weight

    private:
        string firstName;
        string lastName;
        char gender;
        Date dateOfBirth;
        int height; // in inches
        int weight; // in pounds
        
};
#endif