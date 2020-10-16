//The sieve of Eratosthenes
#include <iostream>

using namespace std;

#define TOTAL_INTEGERS 1000000

int main(void){
    
    // bool is 1 byte, int is 4 bytes - creating a bool array to save space
    bool numbers[TOTAL_INTEGERS] = {};

    int multiple;   // track the index to the multiple of current index

    // initialize everything to true
    for (int i=2; i< TOTAL_INTEGERS; i++){
        numbers[i] = true;
    }

    // ignore first two elements
    for (int i=2; i< TOTAL_INTEGERS; i++){
        multiple = 2;
        // set all multiples of current entry to false
        while(i * multiple < TOTAL_INTEGERS){
            numbers[i*multiple] = false;
            multiple++;
        }
    }

    // Print all the prime numbers
    cout << "Prime numbers between 2 and " << TOTAL_INTEGERS << " are: " << endl;
    for (int i=2; i<TOTAL_INTEGERS; i++){
        if (numbers[i] == true){
            cout << i << " ";
        }
    }

    return 0;
}