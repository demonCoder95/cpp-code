// Celsius and Fahrenheit conversions
#include <iostream>
#include <iomanip>

using namespace std;

inline double celsius(double);  // celsius -> fahrenheit
inline double fahrenheit(double);   // fahrenheit -> celsius


#define MAX_CELSIUS 100
#define MIN_CELSIUS 0
#define MAX_FAHRENHEIT 212
#define MIN_FAHRENHEIT 32

int main(void){

    cout << setw(10) << left << "Celsius" << setw(10) << "Fahrenheit" << endl;
    for (int c=MIN_CELSIUS; c<=MAX_CELSIUS; c++){
        cout << fixed << left << setprecision(2) << setw(10) << c << setw(10) << fahrenheit(c) << endl;
    }

    cout << setw(10) << left << "Fahrenheit" << setw(10) << "Celsius" << endl;
    for (int f=MIN_FAHRENHEIT; f<=MAX_FAHRENHEIT; f++){
        cout << fixed << left << setprecision(2) << setw(10) << f << setw(10) << celsius(f) << endl;
    }

    return 0;
}

inline double celsius(double fahrenheit){
    return 5.0/9.0*(fahrenheit-32.0);
}

inline double fahrenheit(double celsius){
    return 9.0/5.0*celsius + 32.0;
}