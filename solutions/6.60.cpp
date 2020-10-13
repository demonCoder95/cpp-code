// CAI - Varying the Types of Problems
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

inline int generateRandom(short);    // generate a random integer

inline string correctResponse(int); // generate response for correct answer
inline string wrongResponse(int);   // generate response for wrong answer

inline void printOperationPrompt(); // prints the operation selection prompt on screen
int performOperation(int, int, short);  // returns result after performing desired operation

inline void printQuestionPrompt(int, int, short);   // prints the question prompt modified by operation type

inline int doOperation(int, int, short);    // perform operation and return result

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
    short operationType = 0;    // type of operation to test

    bool generateOperation = false; // whether to generate a new operation

    int operationResult = 0;    // result of operation between numbers

    printOperationPrompt();
    cin >> operationType;

    // Input verification
    if (operationType < 1 || operationType > 5){
        operationType = 5;
    }

    if (operationType == 5){
        generateOperation = true;
    }

    cout << "Enter the difficulty level for the test (default 1): " << endl;
    cin >> difficultyLevel;

    // Input verification
    if (difficultyLevel < 1 || difficultyLevel > 2){
        difficultyLevel = 1;
    }

    rand1 = generateRandom(difficultyLevel);
    rand2 = generateRandom(difficultyLevel);

    for(int i=0; i<questionsToAsk; i++){
        
            // Generate a random operation for each question
            if (generateOperation == true){
                operationType = 1 + rand() % 4;
            }

            operationResult = doOperation(rand1, rand2, operationType);
        do{
            
            printQuestionPrompt(rand1, rand2, operationType);
            cin >> answer;

            // Random choice of response out of possible 4
            responseNumber = 1 + rand() % 4;

            if (answer == operationResult){
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

inline void printOperationPrompt(){
    cout << "Choose the type of operation for test:" << endl;
    cout << "1- Addition only" << endl;
    cout << "2- Subtraction only" << endl;
    cout << "3- Multiplication only" << endl;
    cout << "4- Division only" << endl;
    cout << "5- Random mix of all (default)" << endl;
}

int performOperation(int rand1, int rand2, short operation){
    switch(operation){

    }
}

inline void printQuestionPrompt(int rand1, int rand2, short operationType){
    string prompt = "How much is " + to_string(rand1);

    switch(operationType){
        case 1: prompt += " + " ; break;
        case 2: prompt += " - " ; break;
        case 3: prompt += " * " ; break;
        case 4: prompt += " / " ; break;
        default: prompt += " This should happen! "; break;
    }

    prompt += to_string(rand2) + "?";

    cout << prompt << endl;

}

inline int doOperation(int rand1, int rand2, short operationType){
    switch(operationType){
        case 1: return rand1 + rand2;
        case 2: return rand1 - rand2;
        case 3: return rand1 * rand2;
        case 4: return rand1 / rand2;
        default: return 0;  // this should never happen
    }
}