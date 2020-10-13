#include <iostream>

using namespace std;

inline bool isEven(int);
inline void printNumber(int);

int main(void){

    int num1, num2, num3;

    cout << "Enter 3 integers: " << endl;
    cin >> num1 >> num2 >> num3;

    printNumber(num1);
    printNumber(num2);
    printNumber(num3);

    return 0;
}

inline bool isEven(int number){
    return number % 2 == 0;
}

inline void printNumber(int number){
    cout << number << " is an " << (isEven(number) ? " even " : " odd ") << " number." << endl;
}