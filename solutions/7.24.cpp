// Knight's Tour problem
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Global macros to store general information
#define BOARD_ROWS 8
#define BOARD_COLUMNS 8
#define MOVE_TYPES 8    // types of move the knight can make
#define MAX_MOVES 64    // maximum moves a knight has to make

// Const arrays are safe to declare as global
/*  All possible moves of the knight are encoded as follows:
    Move k corresponds to movement of horizontal[k] times right
    and vertical[k] times downward
    
    The - sign inverts the direction of movement:
        -vertical is upward movement,
        -horizontal is leftward movement

    k can be from 0 to 7, a knight makes at most  8 moves at any time */
const short horizontal[] = {2, 1, -1, -2, -2, -1, 1, 2};
const short vertical[] = {-1, -2, -2, -1, 1, 2, 2, 1};

/* FUNCTION PROTOTYPES - ALL READ-ONLY ENTRIES ARE DECLARED CONST*/
ushort evaluateMoves(const ushort, const ushort, bool[], const ushort[][BOARD_COLUMNS]); // populate a structure with all possible moves
void printChessBoard(const ushort[][BOARD_COLUMNS]);      // prints the chess board in tabular form

/* update accesibility values, using current possible move values, return next move based on accessibility number*/
ushort evaluateAccessibility(const ushort, const ushort, const bool[], ushort[][BOARD_COLUMNS]);    
/* ************************************************************** */


int main(void){

    // // initialize the PRNG
    // srand(time(NULL));

    // the chess board, each entry will be storing current move number
    ushort chessBoard [BOARD_ROWS][BOARD_COLUMNS] = {};

    /* The accessibility matrix. It tells how many blocks can reach to this 
    one. The heuristic will tend to "minimize" this value as the knight
    progresses*/
    ushort accessibilityMatrix[BOARD_ROWS][BOARD_COLUMNS] = {
        {2, 3, 4, 4, 4, 4, 3 ,2},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {2, 3, 4, 4, 4, 4, 3, 2}
    };

    // store possible moves
    bool possibleMoves[8] = {};

    // choosing a corner to start, a least accessible block
    ushort currentRow = 0;  // current row of the knight's position
    ushort currentColumn = 0;  // current column of the knight's position
    chessBoard[currentRow][currentColumn] = 1;  // mark the starting move
    
    ushort movesLeft = 0;   // number of moves possible from current position
    ushort movesMade = 0;   // number of moves that were made, to detect complete traversal
    ushort nextMoveType = 0;    // move type of next move to make

    /* START TRAVERSING THE BOARD */
    cout << "Starting the Knight's Tour..." << endl;
    for (movesMade = 2; movesMade <= MAX_MOVES; movesMade++){

        // Determine all possible moves from current position
        movesLeft = evaluateMoves(currentRow, currentColumn, possibleMoves, chessBoard);

        if (movesLeft == 0){
            break;  // end the traversal
        }
        cout << "Possible moves: ";
        for (int i=0; i<MOVE_TYPES; i++){
            cout << possibleMoves[i] << " ";
        }
        cout << endl;
        cout << "Moves left " << movesLeft << endl;

        // Choose a move to make, that is to a "least accessible block" on the board
        nextMoveType = evaluateAccessibility(currentRow, currentColumn, possibleMoves, accessibilityMatrix);

        // Make the new move, and update the chess table
        currentRow += vertical[nextMoveType];
        currentColumn += horizontal[nextMoveType];
        chessBoard[currentRow][currentColumn] = movesMade;

    }

    // -1 is to account for terminating condition of for loop
    if (movesMade - 1 == MAX_MOVES){
        cout << "Traversal completed with 64 moves!" << endl;
    }else {
        cout << "Traversal didn't complete. Moves made are " << movesMade << endl;
    }

    printChessBoard(chessBoard);
    printChessBoard(accessibilityMatrix);

    return 0;
}


/* Given a current position (currentRow, currentCol)
tell which move types 0-7 as possible from this position
by populating a bool array
Checks if 1- move goes off the board
          2- move goes to a block already traversed

Returns number of possible moves */
ushort evaluateMoves(const ushort currentRow, const ushort currentColumn, bool possibleMoves[], const ushort chessBoard[][BOARD_COLUMNS]){
    
    ushort moveRow = currentRow, moveColumn = currentColumn;     // position of the potential move
    ushort movesPossible = 0;       // count number of possible moves

    for(int move = 0; move < MOVE_TYPES; move++){
        moveRow += vertical[move];
        moveColumn += horizontal[move];

        // moves that go off the board
        if (moveRow < 0 || moveRow > 7){
            possibleMoves[move] = false;
        }else if (moveColumn < 0 || moveColumn > 7){
            possibleMoves[move] = false;
        }else{
            // see if the move was already made
            if (chessBoard[moveRow][moveColumn] != 0){
                possibleMoves[move] = false;
            }else {
                possibleMoves[move] = true;
                movesPossible++;
            }
        }

        // reset position to current position after checking the potential move
        moveRow = currentRow;
        moveColumn = currentColumn;
    }

    return movesPossible;
}

void printChessBoard(const ushort chessBoard[][BOARD_COLUMNS]){
    cout << "\n\n";
    for (int row = 0; row < BOARD_ROWS; row++){
        for (int column = 0; column < BOARD_COLUMNS; column++){
            cout << setw(4) << chessBoard[row][column];
        }
        cout << endl;
    }
    cout << "\n\n";
}

// reduce accessibility value of each possible move by 1, evaluate next move
ushort evaluateAccessibility(const ushort currentRow, const ushort currentColumn, const bool possibleMoves[], ushort accessibilityMatrix[][BOARD_COLUMNS]){
    ushort moveRow = currentRow, moveColumn = currentColumn;
    cout << "Knight currently at: " << currentRow << "," << currentColumn << endl;
    ushort nextMove = 0;    // the next move number
    ushort accessValue = 8; // start with a maximum value

    // clear the value in the current spot
    accessibilityMatrix[currentRow][currentColumn] = 0;

    // iterate over all possible moves
    for (int move=0; move < MOVE_TYPES; move++){
        
        // we only care if a move is possible
        if (possibleMoves[move] == true){

            // compute potential move coordinates
            moveRow += vertical[move];
            moveColumn += horizontal[move];

            cout << "Looking at move to: (" << moveRow << "," << moveColumn << ")" << endl;

            // compute next move, in case of a tie, first evaluated move will be made
            if (accessibilityMatrix[moveRow][moveColumn] < accessValue){
                cout << "Accessibility to (" << moveRow << "," << moveColumn << ") is " << accessibilityMatrix[moveRow][moveColumn] << endl;
                nextMove = move;
                accessValue = accessibilityMatrix[moveRow][moveColumn];
            }

            // update accessibility value at that point
            accessibilityMatrix[moveRow][moveColumn]--;
        }

        // reset the move coordinates back to current position
        moveRow = currentRow;
        moveColumn = currentColumn;
    }

    cout << "Moving knight to: (" << currentRow + vertical[nextMove] << "," << currentColumn + horizontal[nextMove] << ")...\n" << endl;

    return nextMove;
}