// Function template for determining the minimum
#include <iostream>

using namespace std;

template <typename T>

inline T minimum(T arg1, T arg2){
    
    if (arg1 < arg2){
        
        return arg1;

    }else {
        
        return arg2;
    }
}

int main(void){

    int int1 = 10, int2 = 20;
    float float1 = 1.23, float2 = 3.45;
    char char1 = 'c', char2 = 'F';

    cout << "smaller int is: " << minimum(int1, int2) << endl;
    cout << "smaller float is: " << minimum(float1, float2) << endl;
    cout << "smaller char is: " << minimum(char1, char2) << endl;

    return 0;
}

