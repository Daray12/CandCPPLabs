/*
Daniel Yanez (#5535343)
March 28, 2024
The purpose of this lab is to create a Tic-Tac-Toe game using OOP C++ concepts where a player 
is capable of playing against a computer. It displays a 3x3x3 table and tells the players if a cell 
has already been occupied, if one of the players wins or if there is a draw, and whether the 
player or the AI gets to go first. Furthermore, this version implements two more tables so that
a user is capable of achieving a victory by placing a letter in a cell down the table.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define the TicTacToe class
class TicTacToe {
private:
    vector<vector<vector<char>>> board;  // The game boards
    char currentPlayer;  // The player who is currently making a move

public:
    // Constructor
    TicTacToe() : board(3, vector<vector<char>>(3, vector<char>(3, ' '))), currentPlayer('X') {
        srand(time(0));  // Seed the random number generator
        if (rand() % 2) currentPlayer = 'O';  // Randomly decide who goes first
    }

    // Function to draw the game board
	void drawBoard() {
	    for (int k = 0; k < 3; ++k) {
	        cout << "Board " << k << ":\n"; // Lets the user know what board is which
	        for (int i = 0; i < 3; ++i) { // Rows
	            for (int j = 0; j < 3; ++j) {
	                cout << '|' << (board[k][i][j] == ' ' ? '_' : board[k][i][j]);  // Print each cell
	            }
	            cout << "|\n";  // Print a newline at the end of each row
	        }
	        cout << "\n"; // Separates the tables
	    }
	}
	
    // Function to make a move
    bool makeMove(int row, int col, int boa) {
        if (board[row][col][boa] != ' ') return false;  // If the cell is already occupied, return false
        board[row][col][boa] = currentPlayer;  // Place the current player's mark in the cell
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');  // Switch the current player
        return true;  // Return true to indicate a successful move
    }

    // Function to check if a player has won
	char checkWin() {
	    // Check rows, columns and heights for a win
	    for (int i = 0; i < 3; ++i) {
	        for (int j = 0; j < 3; ++j) {
	            if (board[i][j][0] != ' ' && board[i][j][0] == board[i][j][1] && board[i][j][1] == board[i][j][2]) return board[i][j][0];
	            if (board[i][0][j] != ' ' && board[i][0][j] == board[i][1][j] && board[i][1][j] == board[i][2][j]) return board[i][0][j];
	            if (board[0][i][j] != ' ' && board[0][i][j] == board[1][i][j] && board[1][i][j] == board[2][i][j]) return board[0][i][j];
	        }
	    }
	    // Check diagonals for a win
	    for (int i = 0; i < 3; ++i) {
	        if (board[i][i][i] != ' ' && board[i][i][i] == board[(i+1)%3][(i+1)%3][(i+1)%3] && board[(i+1)%3][(i+1)%3][(i+1)%3] == board[(i+2)%3][(i+2)%3][(i+2)%3]) return board[i][i][i];
	        if (board[i][i][2-i] != ' ' && board[i][i][2-i] == board[(i+1)%3][(i+1)%3][2-((i+1)%3)] && board[(i+1)%3][(i+1)%3][2-((i+1)%3)] == board[(i+2)%3][(i+2)%3][2-((i+2)%3)]) return board[i][i][2-i];
	    }
	    // Check for a draw
	    for (const auto &height : board) {
	        for (const auto &row : height) {
	            for (const auto &cell : row) {
	                if (cell == ' ') return ' ';  // If there are still empty cells, the game is not over
	            }
	        }
	    }
	    return 'D';  // If there are no empty cells and no winner, it's a draw
	}

    // Function to play the game
    void playGame() {
        while (true) {
            drawBoard();
            int row, col, boa;
            if (currentPlayer == 'X') {
                cout << "Enter your move (board, row, and column starting from 0): ";
                cin >> row >> col >> boa;
            } else {
            	// Random moves for the machine
                row = rand() % 3;
                col = rand() % 3;
                boa = rand() % 3;
            }
            if (!makeMove(row, col, boa)) { // If the move is not allowed, let the user continue
                cout << "Illegal move! Try again.\n"; 
                continue;
            }
            char result = checkWin();
            if (result != ' ') {
                drawBoard(); // Keeps on drawing a board while there is not a winner (returned letter from the checkWin() function)
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
