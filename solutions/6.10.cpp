// The inline function as required by the exercise
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

inline double sphereVolume(double);

int main(void){
    double radius, volume;
    cout << "Enter radius of the sphere: ";
    cin >> radius;

    volume = sphereVolume(radius);
    cout << "Radius of sphere: " << setprecision(4) << volume << endl;

    return 0;
}

inline double sphereVolume(double radius){
    return (4.0/3.0 * 3.14159 * pow(radius, 3));
}