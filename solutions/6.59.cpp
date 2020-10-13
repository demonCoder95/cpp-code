// CAI - Adding difficulty levels
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

inline int generateRandom(short);    // generate a random integer

inline string correctResponse(int); // generate response for correct answer
inline string wrongResponse(int);   // generate response for wrong answer

int main(void){

    // seed the random number generator
    srand(time(NULL));

    int rand1, rand2;   // the two randomly generated numbers
    int responseNumber; // random reponse to generate upon answer
    int answer; // answer provided by the student

    const int questionsToAsk = 10;  // ask 10 questions from the student

    bool askAgain = false;  // check whether to ask again

    short correctAnswers = 0;   // keep track of correct answer count

    short difficultyLevel = 1;  // the difficulty level of multiplication

    cout << "Enter the difficulty level for the test (default 1): " << endl;
    cin >> difficultyLevel;

    if (difficultyLevel < 1 || difficultyLevel > 2){
        difficultyLevel = 1;
    }

    rand1 = generateRandom(difficultyLevel);
    rand2 = generateRandom(difficultyLevel);

    for(int i=0; i<questionsToAsk; i++){
        
        do{
            cout << "How much is " << rand1 << " times " << rand2 << "?" << endl;
            cin >> answer;

            // Random choice of response out of possible 4
            responseNumber = 1 + rand() % 4;

            if (answer == rand1*rand2){
                correctAnswers++;
                cout << correctResponse(responseNumber) << endl;
                askAgain = false;
            }else{
                cout << wrongResponse(responseNumber) << endl;
                askAgain = true;
            }
        }while(askAgain);

        // Generate new numbers for the next question
        rand1 = generateRandom(difficultyLevel);
        rand2 = generateRandom(difficultyLevel);
    }

    if (correctAnswers < 7){
        cout << "Please ask your teacher for extra help." << endl;
    }else{
        cout << "Contragulations, you're ready to go to the next level!" << endl;
    }

    return 0;
}

// Generate a random number between 1 and 20
inline int generateRandom(short difficultyLevel){
    
    if (difficultyLevel == 1){
        return 1 + rand() % 8;   // single digit numbers

    }else if (difficultyLevel == 2){
        return 10 + rand() % 90; // double digit numbers
    }
    
}

// Provides correct answer responses
inline string correctResponse(int responseNumber){
    switch(responseNumber){
        case 1: return "Very good!"; break;
        case 2: return "Excellent!"; break;
        case 3: return "Nice work!"; break;
        case 4: return "Keep up the good work!"; break;
        default: return "This shouldn't happen!"; break;
    }
}

// Provides wrong answer responses
inline string wrongResponse(int responseNumber){
    switch(responseNumber){
        case 1: return "No. Please try again."; break;
        case 2: return "Wrong. Try once more."; break;
        case 3: return "Don't give up!"; break;
        case 4: return "No. Keep Trying."; break;
        default: return "This shouldn't happen!"; break;
    }
}