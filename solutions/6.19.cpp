#include <iostream>
#include <cmath>

using namespace std;

inline double hypotenuse(double, double);
inline void printTriangle(double, double, double);

int main(void){
    // sides of the right triangle
    double side1, side2;

    // Printing the first triangle
    side1 = 3.0, side2 = 4.0;
    printTriangle(side1, side2, hypotenuse(side1, side2));

    // Printing the second triangle
    side1 = 5.0, side2 = 12.0;
    printTriangle(side1, side2, hypotenuse(side1, side2));

    // Printing the third triangle
    side1 = 8.0, side2 = 15.0;
    printTriangle(side1, side2, hypotenuse(side1, side2));

    return 0;
}

inline double hypotenuse(double side1, double side2){
    return sqrt(side1*side1 + side2*side2);
}

inline void printTriangle(double side1, double side2, double hypotenuse){
    cout << "Triangle:\nSide1: " << side1 << " Side2: " << side2 << " Hypotenuse: " << hypotenuse << endl;
}