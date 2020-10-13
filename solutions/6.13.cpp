#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){

    double number, roundedNumber;

    cout << "Enter a number: " << endl;
    cin >> number;

    roundedNumber = floor(number + 0.5);
    cout << "Original Number: " << fixed << setprecision(2) << number << " Rounded Number: " << roundedNumber << endl;

    return 0;
}