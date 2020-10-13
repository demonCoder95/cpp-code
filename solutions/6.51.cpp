// Pass by value VS pass by reference

#include <iostream>

using namespace std;

inline int tripleByValue(int);
inline int tripleByReference(int &);

int main(void){

    int count = 5;

    cout << "Count = " << count << endl;
    tripleByValue(count);
    cout << "Count Triple by Value = " << count << endl;
    tripleByReference(count);
    cout << "Count Triple by Reference = " << count << endl;

    return 0;
}

inline int tripleByValue(int count){
    return count *= 3;
}

inline int tripleByReference(int &count){
    return count *= 3;
}


