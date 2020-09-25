// This implements the encryption scheme from exercise 4.35
#include <iostream>
using namespace std;

int main(){
    int inputNumber;

    cout << "Enter 4-digit number to encrypt: " << endl;
    cin >> inputNumber;

    // the 4 digits of the number separated
    int digit1, digit2, digit3, digit4;

    //   1      2      3       4
    // digit1 digit2 digit3 digit4
    digit4 = (inputNumber / 1)% 10;
    digit3 = (inputNumber / 10) % 10;
    digit2 = (inputNumber / 100) % 10;
    digit1 = (inputNumber / 1000) % 10;


    // encryption algorithm
    digit1 = (digit1+7) % 10;
    digit2 = (digit2+7) % 10;
    digit3 = (digit3+7) % 10;
    digit4 = (digit4+7) % 10;

    int temp;
    // swap digit1 and digit3
    temp = digit1;
    digit1 = digit3;
    digit3 = temp;

    // swap digit2 and digit4
    temp = digit2;
    digit2 = digit4;
    digit4 = temp;

    int encryptedNumber = digit1*1000 + digit2*100 + digit3*10 + digit4;
    cout << "The encrypted number is: " << encryptedNumber << endl;

    return 0;
}