// This simulates the game of "craps"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice(); // rolls dice, calculates and displays the sum

int main(){
    // enumeration with constants that represent the game status
    enum Status { CONTINUE, WON, LOST};

    int myPoint;    // points when there is no win/loss on first roll
    Status gameStatus;  // can have CONTINUE, WIN or LOST

    // randomize the random number generator using current time
    srand(time(0));

    int sumOfDice = rollDice();

    switch (sumOfDice){
        case 7:     //win with 7 on first roll
        case 11:    // win with 11 on first roll
            gameStatus = WON;
            break;
        case 2:     // lose with 2 on first roll
        case 3:     // lose with 3 on first roll
        case 12:    // lose with 12 on first roll
            gameStatus = LOST;
            break;
        default:    // did no win or lose, remember the point
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            cout << "Point is " << myPoint << endl;
            break;
    }

    while (gameStatus == CONTINUE){
        sumOfDice = rollDice();

        if (sumOfDice == myPoint){
            gameStatus = WON;
        }else if(sumOfDice == 7){
            gameStatus = LOST;
        }
    }

    if (gameStatus == WON){
        cout << "Player wins" << endl;
    }else{
        cout << "Player loses" << endl;
    }
}

// roll dice, calculate sum and display results
int rollDice(){
    // pick random die values
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;

    int sum = die1 + die2;

    // display result of rolls
    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
    return sum;
}