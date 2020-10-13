#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

inline double roundToInteger(double);
inline double roundToTenths(double);
inline double roundToHundredths(double);
inline double roundToThousandths(double);

inline void printNumber(double);

int main(void){
    double num1, num2, num3;

    cout << "Enter 3 numbers: " << endl;
    cin >> num1 >> num2 >> num3;

    cout << setw(10) << left << "Number" << setw(10) << right << "Integer" << setw(10) 
    << "Tenth" << setw(15) << "Hundredth" << setw(15) << "Thousandth" << endl;
    
    printNumber(num1);
    printNumber(num2);
    printNumber(num3);

    return 0;
}

inline double roundToInteger(double number){
    return floor(number + 0.5);
}

inline double roundToTenths(double number){
    return floor(number * 10 + 0.5) / 10;
}

inline double roundToHundredths(double number){
    return floor(number * 100 + 0.5) / 100;
}

inline double roundToThousandths(double number){
    return floor(number * 1000  + 0.5 ) / 1000;
}

inline void printNumber(double number){
    cout << fixed << left << setw(10) << setprecision(5) << number << setw(10) << right << setprecision(0) << roundToInteger(number) 
         << setw(10) << setprecision(1) << roundToTenths(number) << setw(15) << setprecision(2) 
         << roundToHundredths(number) << setw(15) << setprecision(3) << roundToThousandths(number) << endl;
}