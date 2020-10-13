#include <iostream>

using namespace std;

inline void printSquare(int, char);

int main(void){

    int side;
    char fillChar;

    cout << "Enter the side of asterisk square and fill character: " << endl;
    cin >> side >> fillChar;

    printSquare(side, fillChar);

    return 0;
}

inline void printSquare(int side, char fillChar){
    for (int i=0; i<side; i++){
        for (int j=0; j<side; j++){
            cout << fillChar;
        }
        cout << endl;
    }
}