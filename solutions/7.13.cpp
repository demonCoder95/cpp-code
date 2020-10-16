// Single array questions
#include <iostream>

using namespace std;

int main(void){

    // part a
    int counts[10] = {};

    // part b
    int bonus[15] = {};

    for (int i=0; i<15; i++){
        bonus[i]++;
    }

    // part c
    double monthlyTemperatures[12] = {};
    for (int i=0; i<12; i++){
        cin >> monthlyTemperatures[i];
    }

    // part d
    int bestScores[5] = {92, 10, 54, 123};
    for (int i=0; i<5; i++){
        cout << bestScores[i] << endl;
    }

    return 0;
}