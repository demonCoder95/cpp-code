// Compute area of circle

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

inline double circleArea(double); 

int main(void){
    double radius;

    cout << "Enter the radius: " << endl;
    cin >> radius;

    cout << "The area is: " << setprecision(2) << fixed << circleArea(radius) << endl;

    return 0;
}

inline double circleArea(double radius){
    return M_PI*pow(radius,2);
}