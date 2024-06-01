/*
Daniel Yanez (#5535343)
March 28, 2024
The purpose of this lab is to create a Tic-Tac-Toe game using OOP C++ concepts where a player 
is capable of playing against a computer. It displays a 3x3 table and tells the players if a cell 
has already been occupied, if one of the players wins or if there is a draw, and whether the 
player or the AI gets to go first.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define the TicTacToe class
class TicTacToe {
private:
    vector<vector<char>> board;  // The game board
    char currentPlayer;  // The player who is currently making a move

public:
    // Constructor
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {
        srand(time(0));  // Seed the random number generator
        if (rand() % 2) currentPlayer = 'O';  // Randomly decide who goes first
    }

    // Function to draw the game board
    void drawBoard() {
        for (const auto &row : board) {
            for (const auto &cell : row) {
                cout << '|' << (cell == ' ' ? '_' : cell);  // Print each cell
            }
            cout << "|\n";  // Print a newline at the end of each row
        }
        cout << "\n";
    }

    // Function to make a move
    bool makeMove(int row, int col) {
        if (board[row][col] != ' ') return false;  // If the cell is already occupied, return false
        board[row][col] = currentPlayer;  // Place the current player's mark in the cell
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');  // Switch the current player
        return true;  // Return true to indicate a successful move
    }

    // Function to check if a player has won
    char checkWin() {
        // Check rows and columns for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
        }
        // Check diagonals for a win
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

        // Check for a draw
        for (const auto &row : board) {
            for (const auto &cell : row) {
                if (cell == ' ') return ' ';  // If there are still empty cells, the game is not over
            }
        }
        return 'D';  // If there are no empty cells and no winner, it's a draw
    }

    // Function to play the game
    void playGame() {
        while (true) {
            drawBoard();
            int row, col;
            if (currentPlayer == 'X') {
                cout << "Enter your move (row and column): ";
                cin >> row >> col;
            } else {
                row = rand() % 3;
                col = rand() % 3;
            }
            if (!makeMove(row, col)) {
                cout << "Illegal move! Try again.\n";
                continue;
            }
            char result = checkWin();
            if (result != ' ') {
                drawBoard();
                if (result == 'D') cout << "It's a draw!\n";
                else cout << "Player " << result << " wins!\n";
                break;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
