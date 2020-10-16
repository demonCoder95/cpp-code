// Bubble sort
#include <iostream>

using namespace std;

void bubbleSort(int[], size_t); // implements bubble sort
void printArray(const int[], size_t);   // prints an array provided

#define ARRAY_SIZE 10

int main(void){

    // sample array to test the sorting algorithm
    int numbers[ARRAY_SIZE] = {3, 9, 0, 12, 98, 23, 349, 8, 7, 20};

    // print array before sorting
    printArray(numbers, ARRAY_SIZE);

    bubbleSort(numbers, ARRAY_SIZE);

    // print array after sorting 
    printArray(numbers, ARRAY_SIZE);    

    return 0;
}

void bubbleSort(int numbers[], size_t size){
    
    bool didSwap = false;   // determine if a swap was made, to stop loop

    // continue looping until sorting is done
    do{
        didSwap = false;

        // Iterate once over the whole array
        for(int i=0; i<size-1; i++){

            // determine if next entry is less than current entry
            if (numbers[i] > numbers[i+1]){
                // swap numbers[i] and numbers[i+1]
                numbers[i] = numbers[i] + numbers[i+1]; // a = a+b
                numbers[i+1] = numbers[i] - numbers[i+1];   // b = a-b = a + b - b = a so b=a
                numbers[i] = numbers[i] - numbers[i+1]; // a = a - b -> a+b - a =b so a = b
                didSwap = true;
            }
        }
    }while(didSwap);
}

void printArray(const int numbers[], size_t size){

    for (int i=0; i<size; i++){
            cout << numbers[i] << " ";
        }
        cout << endl;
}