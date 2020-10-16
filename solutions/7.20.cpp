#include <iostream>

using namespace std;

void displayMenu(); // display the entry menu
void displayBoardingPass(unsigned short int); // display a passenger's boarding pass given seat#
bool flightIsFull(const bool[], unsigned short int);  // determine if flight is full
unsigned short int assignSeat(bool[], unsigned short int, bool);    // assign a seat in given class

#define NUMBER_OF_SEATS 10  // total number of seats in the plane

int main(void){
    // seating choice of customer
    unsigned short int seatingChoice = 0;
    // seating arrangement of flight
    bool seatingChart[NUMBER_OF_SEATS] = {};
    // check status of assignment
    unsigned short int assignedSeat = 0;

    do{
        displayMenu();
        cin >> seatingChoice;

        // validate input
        if (seatingChoice < 1 || seatingChoice > 2){
            cout <<"Invalid entry. Try again" << endl;
            continue;
        }
        
        assignedSeat = assignSeat(seatingChart, NUMBER_OF_SEATS, seatingChoice == 1? true:false);

        if(assignedSeat == 0 && seatingChoice == 1){
            cout << "Sorry, \"First Class\" is full. Try again." << endl;

        }else if (assignedSeat == 0 && seatingChoice == 2){
            cout << "Sorry, \"Economy Class\" is full. Try again." << endl;

        }else {
            cout << "Seat assigned successfully! Please collect your boarding pass." << endl;
            displayBoardingPass(assignedSeat);
        }

    }while(flightIsFull(seatingChart, NUMBER_OF_SEATS) != true);
    
    cout << "Apologies, the flight is full." << endl;
    cout << "Next flight leaves in 3 hours." << endl;

    return 0;
}

void displayMenu(){
    cout << "Welcome to Weird Planes Airways!" << endl;
    cout << "Please type 1 for \"First Class\"" << endl;
    cout << "Please type 2 for \"Economy\"" << endl;
    cout << ">";
}

void displayBoardingPass(unsigned short int seatNumber){

    cout << "\n\n=======================" << endl;
    cout << "BOARDING PASS" << endl;
    cout << "Seat#: " << seatNumber << endl;
    cout << "Class: " << (seatNumber <= 5? "First Class" : "Economy") << endl;
    cout << "=======================\n\n" << endl;
}

bool flightIsFull(const bool seatingChart[], unsigned short int numberOfSeats){
    bool full = true;
    for (unsigned short int seat = 0; seat < numberOfSeats; seat++){
        full &= seatingChart[seat];     // logical AND of occupied status of each seat
    }
    return full;
}

unsigned short int assignSeat(bool seatingChart[], unsigned short int numberOfSeats, bool firstClass){
    // Try to assign a seat in first class
    if (firstClass){
        for(int seat = 0; seat < numberOfSeats/2; seat++){
            if (seatingChart[seat] == false){
                seatingChart[seat] = true;
                return seat+1;
            }
        }
    }else {
    // Try to assign seat in economy class
        for (int seat = numberOfSeats/2; seat <numberOfSeats; seat++){
            if (seatingChart[seat] == false){
                seatingChart[seat] = true;
                return seat +1;
            }
        }
    }
    // 0 means no seat could be assigned
    return 0;
}