// This simulates the game of "craps"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice(); // rolls dice, calculates and displays the sum

#define NUMBER_OF_GAMES 1000   // number of games to simulate
#define ROLL_COUNT  22  // roll numbers to keep track of, for stats

int main(){
    // enumeration with constants that represent the game status
    enum Status { CONTINUE, WON, LOST};

    int myPoint;    // points when there is no win/loss on first roll
    Status gameStatus;  // can have CONTINUE, WIN or LOST

    // randomize the random number generator using current time
    srand(time(0));

    // arrays to store statistical data of games
    unsigned int winCount[ROLL_COUNT] = {};
    unsigned int lossCount[ROLL_COUNT] = {};
    unsigned int rollCount = 0; // the current roll number the game is at

    /* START OF THE GAME */
    for (int game=0; game< NUMBER_OF_GAMES; game++){

        int sumOfDice = rollDice();
        rollCount++;    // increase roll count

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
                break;
        }

        while (gameStatus == CONTINUE){
            rollCount++;    // increase roll count
            sumOfDice = rollDice();

            if (sumOfDice == myPoint){
                gameStatus = WON;
            }else if(sumOfDice == 7){
                gameStatus = LOST;
            }
        }

        // Update statistics at the end of the game
        if (rollCount < 20){
            if(gameStatus == WON){
                winCount[rollCount]++;
            }else if (gameStatus == LOST){
                lossCount[rollCount]++;
            }
        }else {
            if(gameStatus == WON){
                winCount[ROLL_COUNT-1]++;
            }else if (gameStatus == LOST){
                lossCount[ROLL_COUNT-1]++;
            }
        }

        // reset the count for next game
        rollCount = 0;
    }
    /* END OF THE GAME */

    /* PRINT THE RESULTS OF ALL GAMES */
    cout << left << setw(10) << "Roll #" << setw(10) << "Games WON" << setw(10) << "Games LOST" << endl;
    for (int i=1; i<ROLL_COUNT-1; i++){
        cout << left << setw(10) << i << setw(10) << winCount[i] << setw(10) << lossCount[i] << endl;
    }
    cout << left << setw(10) << "20+" << setw(10) << winCount[ROLL_COUNT-1] << setw(10) << lossCount[ROLL_COUNT-1] << endl;
}

// roll dice, calculate sum and display results
int rollDice(){
    // pick random die values
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;

    int sum = die1 + die2;

    return sum;
}