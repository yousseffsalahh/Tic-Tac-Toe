#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char currentPlayer = 'X';

void drawBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << "\n";
        if(i < 2) cout << "--|---|--\n";
    }
    cout << "\n";
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

void makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
}

int main() {
    int move;
    int turns = 0;

    while(true) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> move;

        if(move < 1 || move > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        makeMove(move);
        turns++;

        if(checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if(turns == 9) {
            drawBoard();
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
