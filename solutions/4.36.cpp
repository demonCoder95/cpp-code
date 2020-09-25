/* Given the current population and the estimated constant population growth rate,
this program computes the population of Earth for the next 75 years and tabulates it*/
#include <iostream>
#include <iomanip>

using namespace std;

// All the constants can be defined as macros
#define CURRENT_POPULATION 7800000000  // 7.8 billion
#define GROWTH_RATE 1.05   // 1.05% per year
#define NUMBER_OF_YEARS 75 // number of years to estimate

int main(){

    cout << "YEAR\tNET POPULATION\t\tPOPULATION GROWTH" << endl;
    for(int year = 1; year <= NUMBER_OF_YEARS; year++){
        cout << 2020+year << "\t" << fixed << setprecision(0) << CURRENT_POPULATION + (CURRENT_POPULATION*GROWTH_RATE)*year 
             << "\t\t" << (CURRENT_POPULATION*GROWTH_RATE)*year << endl;
    }

    return 0;
}