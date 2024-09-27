#include<iostream>
using namespace std;
char board[3][3] =   {{'1','2','3'} , {'4','5', '6'}, {'7','8', '9'}};
char currentMark;
int currentPlayer;

void resetBoard(){
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + count; // Assign values (1-9)
            count++;
        }
    }
}
//creating the board
void Board(){
      cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// function to mark X or O on the board

bool placeMarker(int slot){
    int row = (slot - 1) / 3; // Row
    int col = (slot - 1) % 3; // Column

    // Check if the slot is taken or not
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMark;
        return true;
    }
    return false;
}

// function to check for winner

int checkWin(){
    //for rows

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }
    // for columns
     for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }

    //check diagonal

   if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }
}
//funtion to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMark = (currentMark == 'X') ? 'O' : 'X';
}


//game function

void game(){
   currentPlayer = 1;
    currentMark = 'X';
    int winner = 0;
    int slot;
    Board();

  //loop for max of 9 turns
 for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << " (" << currentMark << ")'s turn. Enter your slot (1-9): ";
        cin >> slot;

        // Validate the input and make sure the slot is valid
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid slot!! Please choose an available slot between 1 and 9\n";
            i--; // Retry if invalid slot
            continue;
        }

  Board();
  winner = checkWin();

  //// to check if the current player has won

 if (winner == 1) {
            cout << "Player 1 (X) wins!\n";
            break;
        } else if (winner == 2) {
            cout << "Player 2 (O) wins!\n";
            break;
        }

        switchPlayer(); // Switch to the other player
    }

//if no winner and the board is full , its a draw
if (winner == 0) {
        cout << "It's a draw!\n";
    }
}

int main(){
    char playAgain;
    do {
        resetBoard(); // Reset the board
        game(); // Start the game

        // Ask players if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

