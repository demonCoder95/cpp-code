#include <iostream>

using namespace std;

inline void printSquare(int);

int main(void){

    int side;

    cout << "Enter the side of asterisk square: " << endl;
    cin >> side;

    printSquare(side);

    return 0;
}

inline void printSquare(int side){
    for (int i=0; i<side; i++){
        for (int j=0; j<side; j++){
            cout << "*";
        }
        cout << endl;
    }
}