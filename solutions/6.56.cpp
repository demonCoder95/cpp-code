// Computer Assisted Instruction
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

inline int generateRandom();    // generate a random integer

int main(void){

    // seed the random number generator
    srand(time(NULL));

    int rand1, rand2;   // the two randomly generated numbers
    int answer; // answer provided by the student

    const int questionsToAsk = 10;  // ask 10 questions from the student

    bool askAgain = false;  // check whether to ask again

    rand1 = generateRandom();
    rand2 = generateRandom();

    for(int i=0; i<questionsToAsk; i++){
        do{
            cout << "How much is " << rand1 << " times " << rand2 << "?" << endl;
            cin >> answer;

            if (answer == rand1*rand2){
                cout << "Very good!" << endl;
                askAgain = false;
            }else{
                cout << "No. Please Try again" << endl;
                askAgain = true;
            }
        }while(askAgain);

        // Generate new numbers for the next question
        rand1 = generateRandom();
        rand2 = generateRandom();
    }

    return 0;
}

// Generate a random number between 1 and 20
inline int generateRandom(){
    return 1 + rand() % 20;
}